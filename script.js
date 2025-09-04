// Gambling-related keywords and patterns
const gamblingKeywords = [
    'bet', 'betting', 'gambling', 'casino', 'poker', 'slots', 'lottery', 'lotto',
    'sports betting', 'online casino', 'real money', 'jackpot', 'win big',
    'odds', 'wager', 'stake', 'deposit bonus', 'free spins', 'cash out',
    'sportsbook', 'bookmaker', 'parlay', 'teaser', 'futures', 'live betting',
    'mobile betting', 'instant win', 'scratch card', 'bingo', 'keno',
    'roulette', 'blackjack', 'craps', 'baccarat', 'video poker'
];

const gamblingDomains = [
    'bet365', 'draftkings', 'fanduel', 'caesars', 'mgm', 'bovada',
    'betway', '888casino', 'pokerstars', 'partypoker', 'unibet',
    'williamhill', 'ladbrokes', 'paddypower', 'betfair', 'skybet',
    'powerball', 'megamillions', 'eurojackpot', 'euromillions'
];

// Initialize the app
document.addEventListener('DOMContentLoaded', function() {
    loadStreak();
    loadLastCheckIn();
    updateMotivation();
    registerServiceWorker();
});

// Register service worker for offline functionality
function registerServiceWorker() {
    if ('serviceWorker' in navigator) {
        navigator.serviceWorker.register('/sw.js')
            .then(function(registration) {
                console.log('ServiceWorker registration successful');
            })
            .catch(function(err) {
                console.log('ServiceWorker registration failed');
            });
    }
}

// Streak tracking functionality
function checkIn() {
    const today = new Date().toDateString();
    const lastCheckIn = localStorage.getItem('lastCheckIn');
    
    if (lastCheckIn !== today) {
        const currentStreak = parseInt(localStorage.getItem('streak') || '0');
        const newStreak = currentStreak + 1;
        
        localStorage.setItem('streak', newStreak.toString());
        localStorage.setItem('lastCheckIn', today);
        
        document.getElementById('streakCount').textContent = newStreak;
        
        // Show success message
        showNotification('Great job! You\'ve checked in for today. Keep up the amazing work!', 'success');
        
        // Update button text temporarily
        const btn = document.querySelector('.check-in-btn');
        btn.textContent = '✅ Checked In Today!';
        btn.style.background = 'linear-gradient(45deg, #48bb78, #38a169)';
        
        setTimeout(() => {
            btn.textContent = '✅ Today\'s Check-in';
            btn.style.background = 'linear-gradient(45deg, #667eea, #764ba2)';
        }, 2000);
    } else {
        showNotification('You\'ve already checked in today! Come back tomorrow.', 'info');
    }
}

function loadStreak() {
    const streak = localStorage.getItem('streak') || '0';
    document.getElementById('streakCount').textContent = streak;
}

function loadLastCheckIn() {
    const lastCheckIn = localStorage.getItem('lastCheckIn');
    const today = new Date().toDateString();
    
    if (lastCheckIn === today) {
        const btn = document.querySelector('.check-in-btn');
        btn.textContent = '✅ Checked In Today!';
        btn.style.background = 'linear-gradient(45deg, #48bb78, #38a169)';
    }
}

// URL checking functionality
function checkURL() {
    const urlInput = document.getElementById('urlInput').value.trim();
    const resultDiv = document.getElementById('urlResult');
    
    if (!urlInput) {
        showNotification('Please enter a URL to check.', 'warning');
        return;
    }
    
    try {
        const url = new URL(urlInput);
        const domain = url.hostname.toLowerCase();
        
        // Check if domain contains gambling keywords
        const isGambling = gamblingDomains.some(gamblingDomain => 
            domain.includes(gamblingDomain.toLowerCase())
        ) || gamblingKeywords.some(keyword => 
            domain.includes(keyword.toLowerCase())
        );
        
        if (isGambling) {
            resultDiv.innerHTML = `
                <div class="result warning">
                    ⚠️ <strong>Warning:</strong> This website appears to be gambling-related.
                    <br><br>
                    <strong>Recommendation:</strong> Avoid this site and redirect your attention to something positive.
                    <br><br>
                    <button onclick="redirectToPositive()" style="background: #48bb78; margin-top: 10px;">
                        🎯 Redirect to Positive Activity
                    </button>
                </div>
            `;
        } else {
            resultDiv.innerHTML = `
                <div class="result safe">
                    ✅ <strong>Safe:</strong> This website doesn't appear to be gambling-related.
                </div>
            `;
        }
    } catch (error) {
        resultDiv.innerHTML = `
            <div class="result warning">
                ❌ <strong>Error:</strong> Please enter a valid URL.
            </div>
        `;
    }
}

// Text checking functionality
function checkText() {
    const textInput = document.getElementById('textInput').value.trim();
    const resultDiv = document.getElementById('textResult');
    
    if (!textInput) {
        showNotification('Please enter some text to check.', 'warning');
        return;
    }
    
    const text = textInput.toLowerCase();
    const foundKeywords = gamblingKeywords.filter(keyword => 
        text.includes(keyword.toLowerCase())
    );
    
    if (foundKeywords.length > 0) {
        resultDiv.innerHTML = `
            <div class="result warning">
                ⚠️ <strong>Warning:</strong> This text contains gambling-related content.
                <br><br>
                <strong>Found keywords:</strong> ${foundKeywords.join(', ')}
                <br><br>
                <strong>Recommendation:</strong> Consider avoiding this content and focus on positive alternatives.
            </div>
        `;
    } else {
        resultDiv.innerHTML = `
            <div class="result safe">
                ✅ <strong>Safe:</strong> No gambling-related content detected in this text.
            </div>
        `;
    }
}

// Motivation system
const motivations = [
    "Every day you stay strong is a victory. You're building a better future for yourself.",
    "Your future self will thank you for the choices you make today.",
    "You are stronger than any temptation. Your willpower is growing every day.",
    "Focus on what you're gaining, not what you're giving up.",
    "Every 'no' to gambling is a 'yes' to your dreams and goals.",
    "You're not missing out on gambling - you're gaining freedom and peace of mind.",
    "Your mental health and financial security are worth more than any temporary thrill.",
    "You're creating a legacy of strength and self-control for future generations.",
    "Every day clean is a step toward the life you truly want.",
    "You have the power to rewrite your story, one day at a time."
];

function updateMotivation() {
    const motivationText = document.getElementById('motivationText');
    const randomMotivation = motivations[Math.floor(Math.random() * motivations.length)];
    motivationText.textContent = randomMotivation;
}

function newMotivation() {
    updateMotivation();
    showNotification('New motivation loaded! Keep pushing forward! 💪', 'success');
}

// Utility functions
function showNotification(message, type = 'info') {
    // Create notification element
    const notification = document.createElement('div');
    notification.className = `notification ${type}`;
    notification.textContent = message;
    
    // Style the notification
    notification.style.cssText = `
        position: fixed;
        top: 20px;
        right: 20px;
        padding: 15px 20px;
        border-radius: 8px;
        color: white;
        font-weight: 500;
        z-index: 1000;
        max-width: 300px;
        box-shadow: 0 4px 12px rgba(0,0,0,0.15);
        transform: translateX(100%);
        transition: transform 0.3s ease;
    `;
    
    // Set background color based on type
    switch(type) {
        case 'success':
            notification.style.background = '#48bb78';
            break;
        case 'warning':
            notification.style.background = '#ed8936';
            break;
        case 'error':
            notification.style.background = '#f56565';
            break;
        default:
            notification.style.background = '#667eea';
    }
    
    // Add to page
    document.body.appendChild(notification);
    
    // Animate in
    setTimeout(() => {
        notification.style.transform = 'translateX(0)';
    }, 100);
    
    // Remove after 5 seconds
    setTimeout(() => {
        notification.style.transform = 'translateX(100%)';
        setTimeout(() => {
            document.body.removeChild(notification);
        }, 300);
    }, 5000);
}

function redirectToPositive() {
    const positiveActivities = [
        'https://www.youtube.com/watch?v=dQw4w9WgXcQ', // Rick Roll (fun distraction)
        'https://www.calm.com', // Meditation app
        'https://www.duolingo.com', // Language learning
        'https://www.khanacademy.org', // Educational content
        'https://www.ted.com' // Inspirational talks
    ];
    
    const randomActivity = positiveActivities[Math.floor(Math.random() * positiveActivities.length)];
    window.open(randomActivity, '_blank');
    
    showNotification('Redirected to a positive activity! Stay focused on your goals! 🎯', 'success');
}

// Add some additional helpful features
function addHelpfulFeatures() {
    // Add keyboard shortcuts
    document.addEventListener('keydown', function(e) {
        if (e.ctrlKey && e.key === 'k') {
            e.preventDefault();
            document.getElementById('urlInput').focus();
        }
        if (e.ctrlKey && e.key === 't') {
            e.preventDefault();
            document.getElementById('textInput').focus();
        }
    });
    
    // Add tooltips
    const tooltips = document.querySelectorAll('[data-tooltip]');
    tooltips.forEach(element => {
        element.addEventListener('mouseenter', showTooltip);
        element.addEventListener('mouseleave', hideTooltip);
    });
}

// Initialize helpful features
addHelpfulFeatures();