# NDIS Provider Pro - Technical Implementation Plan

## Technology Stack

### Backend Framework
- **Python 3.11+**: Modern Python with type hints and performance improvements
- **Django 4.2+**: Full-featured web framework with built-in admin and ORM
- **Django REST Framework**: For building RESTful APIs
- **Django Channels**: For WebSocket support and real-time features

### Database & Caching
- **PostgreSQL 15+**: Primary database for production
- **Redis 7+**: Caching, session storage, and message queuing
- **Django ORM**: Object-relational mapping with migrations

### Frontend
- **React.js 18+**: Modern frontend framework with hooks
- **TypeScript**: Type-safe JavaScript development
- **Material-UI (MUI)**: Component library for consistent design
- **Redux Toolkit**: State management for complex applications

### Mobile Applications
- **React Native**: Cross-platform mobile development
- **Expo**: Development tools and services for React Native

### Infrastructure & Deployment
- **Docker**: Containerization for consistent environments
- **AWS/Azure**: Cloud infrastructure and services
- **Nginx**: Web server and reverse proxy
- **Gunicorn**: WSGI server for Django
- **Celery**: Asynchronous task processing

## Project Structure

```
ndis_provider_pro/
├── backend/                          # Django backend
│   ├── manage.py
│   ├── requirements.txt
│   ├── ndis_pro/                     # Main Django project
│   │   ├── __init__.py
│   │   ├── settings/
│   │   │   ├── __init__.py
│   │   │   ├── base.py
│   │   │   ├── development.py
│   │   │   ├── production.py
│   │   │   └── testing.py
│   │   ├── urls.py
│   │   ├── wsgi.py
│   │   └── asgi.py
│   ├── apps/                         # Django applications
│   │   ├── __init__.py
│   │   ├── accounts/                 # User management
│   │   ├── providers/                # Provider management
│   │   ├── participants/             # Participant management
│   │   ├── finances/                 # Financial management
│   │   ├── workforce/                # Workforce management
│   │   ├── quality/                  # Quality & compliance
│   │   ├── services/                 # Service delivery
│   │   ├── reporting/                # Reporting & analytics
│   │   ├── mobile/                   # Mobile API endpoints
│   │   └── integrations/             # External integrations
│   ├── core/                         # Core functionality
│   │   ├── __init__.py
│   │   ├── models.py                 # Abstract base models
│   │   ├── permissions.py            # Custom permissions
│   │   ├── middleware.py             # Custom middleware
│   │   ├── decorators.py             # Custom decorators
│   │   └── utils.py                  # Utility functions
│   ├── api/                          # API layer
│   │   ├── __init__.py
│   │   ├── v1/                       # API version 1
│   │   │   ├── __init__.py
│   │   │   ├── urls.py
│   │   │   ├── serializers.py        # Common serializers
│   │   │   └── views.py              # Common views
│   │   └── middleware.py             # API middleware
│   ├── static/                       # Static files
│   ├── media/                        # User uploaded files
│   ├── templates/                    # Django templates
│   ├── tests/                        # Test suite
│   └── docs/                         # Documentation
├── frontend/                         # React frontend
│   ├── package.json
│   ├── public/
│   ├── src/
│   │   ├── components/               # Reusable components
│   │   ├── pages/                    # Page components
│   │   ├── hooks/                    # Custom hooks
│   │   ├── services/                 # API services
│   │   ├── store/                    # Redux store
│   │   ├── utils/                    # Utility functions
│   │   └── types/                    # TypeScript types
│   └── build/
├── mobile/                           # React Native app
│   ├── package.json
│   ├── App.js
│   ├── src/
│   │   ├── components/
│   │   ├── screens/
│   │   ├── services/
│   │   ├── store/
│   │   └── utils/
│   └── android/ & ios/
├── docker/                           # Docker configuration
│   ├── Dockerfile
│   ├── docker-compose.yml
│   └── nginx/
├── scripts/                          # Deployment scripts
├── requirements/                     # Python requirements
│   ├── base.txt
│   ├── development.txt
│   ├── production.txt
│   └── testing.txt
└── README.md
```

## Django Applications Structure

### 1. Accounts App (User Management)
```
apps/accounts/
├── __init__.py
├── admin.py
├── apps.py
├── models.py
├── serializers.py
├── views.py
├── urls.py
├── permissions.py
├── signals.py
├── tests/
└── migrations/
```

**Key Models:**
- User (extends AbstractUser)
- UserProfile
- UserRole
- Permission
- UserSession

### 2. Providers App (Provider Management)
```
apps/providers/
├── __init__.py
├── admin.py
├── apps.py
├── models.py
├── serializers.py
├── views.py
├── urls.py
├── services.py
├── tests/
└── migrations/
```

**Key Models:**
- Provider
- Location
- ProviderSettings
- ProviderDocument

### 3. Participants App (Participant Management)
```
apps/participants/
├── __init__.py
├── admin.py
├── apps.py
├── models.py
├── serializers.py
├── views.py
├── urls.py
├── services.py
├── tests/
└── migrations/
```

**Key Models:**
- Participant
- ParticipantGoal
- ParticipantDocument
- ServicePlan
- ServiceItem

### 4. Finances App (Financial Management)
```
apps/finances/
├── __init__.py
├── admin.py
├── apps.py
├── models.py
├── serializers.py
├── views.py
├── urls.py
├── services.py
├── tasks.py
├── tests/
└── migrations/
```

**Key Models:**
- NDISPlan
- NDISClaim
- ClaimItem
- Payment
- BudgetCategory
- Invoice

### 5. Workforce App (Workforce Management)
```
apps/workforce/
├── __init__.py
├── admin.py
├── apps.py
├── models.py
├── serializers.py
├── views.py
├── urls.py
├── services.py
├── tasks.py
├── tests/
└── migrations/
```

**Key Models:**
- Worker
- Qualification
- Training
- WorkSchedule
- TimeRecord

### 6. Quality App (Quality & Compliance)
```
apps/quality/
├── __init__.py
├── admin.py
├── apps.py
├── models.py
├── serializers.py
├── views.py
├── urls.py
├── services.py
├── tasks.py
├── tests/
└── migrations/
```

**Key Models:**
- NDISStandard
- Compliance
- Incident
- IncidentAction
- AuditRecord

### 7. Services App (Service Delivery)
```
apps/services/
├── __init__.py
├── admin.py
├── apps.py
├── models.py
├── serializers.py
├── views.py
├── urls.py
├── services.py
├── tasks.py
├── tests/
└── migrations/
```

**Key Models:**
- Service
- ServiceDelivery
- ServiceOutcome
- ServiceNote
- ServicePhoto

### 8. Reporting App (Reporting & Analytics)
```
apps/reporting/
├── __init__.py
├── admin.py
├── apps.py
├── models.py
├── serializers.py
├── views.py
├── urls.py
├── services.py
├── tasks.py
├── tests/
└── migrations/
```

**Key Models:**
- Report
- ReportTemplate
- Dashboard
- ReportData
- ReportExport

## Core Models Implementation

### Base Models
```python
# core/models.py
from django.db import models
from django.contrib.auth import get_user_model

class TimeStampedModel(models.Model):
    """Abstract base model with created and updated timestamps."""
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

    class Meta:
        abstract = True

class SoftDeleteModel(models.Model):
    """Abstract base model with soft delete functionality."""
    is_deleted = models.BooleanField(default=False)
    deleted_at = models.DateTimeField(null=True, blank=True)
    deleted_by = models.ForeignKey(
        get_user_model(),
        on_delete=models.SET_NULL,
        null=True,
        blank=True,
        related_name='%(class)s_deleted'
    )

    class Meta:
        abstract = True

class ProviderModel(models.Model):
    """Abstract base model for provider-specific models."""
    provider = models.ForeignKey(
        'providers.Provider',
        on_delete=models.CASCADE,
        related_name='%(class)s_instances'
    )

    class Meta:
        abstract = True
```

### User Management Models
```python
# apps/accounts/models.py
from django.contrib.auth.models import AbstractUser
from django.db import models
from core.models import TimeStampedModel, ProviderModel

class User(AbstractUser, TimeStampedModel):
    """Custom user model extending Django's AbstractUser."""
    email = models.EmailField(unique=True)
    provider = models.ForeignKey(
        'providers.Provider',
        on_delete=models.CASCADE,
        null=True,
        blank=True
    )
    location = models.ForeignKey(
        'providers.Location',
        on_delete=models.SET_NULL,
        null=True,
        blank=True
    )
    is_active = models.BooleanField(default=True)
    last_login = models.DateTimeField(null=True, blank=True)
    
    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = ['username']

class UserRole(TimeStampedModel, ProviderModel):
    """User roles for the provider organization."""
    name = models.CharField(max_length=100)
    description = models.TextField(blank=True)
    permissions = models.ManyToManyField('Permission', blank=True)
    
    class Meta:
        unique_together = ['provider', 'name']

class Permission(TimeStampedModel):
    """System permissions for role-based access control."""
    name = models.CharField(max_length=100, unique=True)
    description = models.TextField(blank=True)
    module = models.CharField(max_length=50)
    action = models.CharField(max_length=50)
    
    class Meta:
        unique_together = ['module', 'action']
```

### Provider Models
```python
# apps/providers/models.py
from django.db import models
from core.models import TimeStampedModel

class Provider(TimeStampedModel):
    """NDIS service provider organization."""
    name = models.CharField(max_length=200)
    ABN = models.CharField(max_length=11, unique=True)
    NDIS_number = models.CharField(max_length=50, unique=True)
    registration_date = models.DateField()
    status = models.CharField(
        max_length=20,
        choices=[
            ('active', 'Active'),
            ('suspended', 'Suspended'),
            ('cancelled', 'Cancelled'),
        ],
        default='active'
    )
    contact_email = models.EmailField()
    contact_phone = models.CharField(max_length=20)
    address = models.TextField()
    
    class Meta:
        verbose_name = 'Provider'
        verbose_name_plural = 'Providers'

class Location(TimeStampedModel):
    """Provider location/branch office."""
    provider = models.ForeignKey(
        Provider,
        on_delete=models.CASCADE,
        related_name='locations'
    )
    name = models.CharField(max_length=200)
    address = models.TextField()
    phone = models.CharField(max_length=20)
    manager = models.ForeignKey(
        'accounts.User',
        on_delete=models.SET_NULL,
        null=True,
        blank=True,
        related_name='managed_locations'
    )
    is_active = models.BooleanField(default=True)
```

## API Implementation

### API Structure
```python
# api/v1/urls.py
from django.urls import path, include

urlpatterns = [
    path('auth/', include('apps.accounts.api.urls')),
    path('providers/', include('apps.providers.api.urls')),
    path('participants/', include('apps.participants.api.urls')),
    path('finances/', include('apps.finances.api.urls')),
    path('workforce/', include('apps.workforce.api.urls')),
    path('quality/', include('apps.quality.api.urls')),
    path('services/', include('apps.services.api.urls')),
    path('reporting/', include('apps.reporting.api.urls')),
    path('mobile/', include('apps.mobile.api.urls')),
]
```

### Serializer Example
```python
# apps/participants/serializers.py
from rest_framework import serializers
from .models import Participant, ParticipantGoal, ServicePlan

class ParticipantGoalSerializer(serializers.ModelSerializer):
    class Meta:
        model = ParticipantGoal
        fields = '__all__'

class ServicePlanSerializer(serializers.ModelSerializer):
    class Meta:
        model = ServicePlan
        fields = '__all__'

class ParticipantSerializer(serializers.ModelSerializer):
    goals = ParticipantGoalSerializer(many=True, read_only=True)
    service_plans = ServicePlanSerializer(many=True, read_only=True)
    
    class Meta:
        model = Participant
        fields = '__all__'
        read_only_fields = ['created_at', 'updated_at']
    
    def create(self, validated_data):
        validated_data['provider'] = self.context['request'].user.provider
        return super().create(validated_data)
```

### View Example
```python
# apps/participants/views.py
from rest_framework import viewsets, permissions
from rest_framework.decorators import action
from rest_framework.response import Response
from .models import Participant, ParticipantGoal
from .serializers import ParticipantSerializer, ParticipantGoalSerializer
from .permissions import IsProviderUser

class ParticipantViewSet(viewsets.ModelViewSet):
    """ViewSet for participant management."""
    queryset = Participant.objects.all()
    serializer_class = ParticipantSerializer
    permission_classes = [IsProviderUser]
    
    def get_queryset(self):
        """Filter participants by user's provider."""
        return self.queryset.filter(provider=self.request.user.provider)
    
    @action(detail=True, methods=['post'])
    def add_goal(self, request, pk=None):
        """Add a new goal to a participant."""
        participant = self.get_object()
        serializer = ParticipantGoalSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save(participant=participant)
            return Response(serializer.data, status=201)
        return Response(serializer.errors, status=400)
    
    @action(detail=True, methods=['get'])
    def goals(self, request, pk=None):
        """Get all goals for a participant."""
        participant = self.get_object()
        goals = participant.goals.all()
        serializer = ParticipantGoalSerializer(goals, many=True)
        return Response(serializer.data)
```

## Authentication & Permissions

### Custom Permissions
```python
# apps/accounts/permissions.py
from rest_framework import permissions

class IsProviderUser(permissions.BasePermission):
    """Allow access only to users associated with a provider."""
    
    def has_permission(self, request, view):
        return bool(
            request.user and
            request.user.is_authenticated and
            request.user.provider
        )

class IsProviderOwner(permissions.BasePermission):
    """Allow access only to provider owners."""
    
    def has_permission(self, request, view):
        return bool(
            request.user and
            request.user.is_authenticated and
            request.user.provider and
            request.user.roles.filter(name='Owner').exists()
        )

class HasModulePermission(permissions.BasePermission):
    """Check if user has permission for specific module and action."""
    
    def __init__(self, module, action):
        self.module = module
        self.action = action
    
    def has_permission(self, request, view):
        if not request.user.is_authenticated:
            return False
        
        # Check if user has the required permission
        return request.user.has_perm(f"{self.module}.{self.action}")
```

### JWT Authentication
```python
# settings/base.py
REST_FRAMEWORK = {
    'DEFAULT_AUTHENTICATION_CLASSES': [
        'rest_framework_simplejwt.authentication.JWTAuthentication',
    ],
    'DEFAULT_PERMISSION_CLASSES': [
        'rest_framework.permissions.IsAuthenticated',
    ],
    'DEFAULT_PAGINATION_CLASS': 'rest_framework.pagination.PageNumberPagination',
    'PAGE_SIZE': 20,
}

# JWT Settings
SIMPLE_JWT = {
    'ACCESS_TOKEN_LIFETIME': timedelta(hours=1),
    'REFRESH_TOKEN_LIFETIME': timedelta(days=7),
    'ROTATE_REFRESH_TOKENS': True,
    'BLACKLIST_AFTER_ROTATION': True,
    'UPDATE_LAST_LOGIN': True,
}
```

## Background Tasks

### Celery Configuration
```python
# settings/base.py
CELERY_BROKER_URL = os.environ.get('REDIS_URL', 'redis://localhost:6379/0')
CELERY_RESULT_BACKEND = os.environ.get('REDIS_URL', 'redis://localhost:6379/0')
CELERY_ACCEPT_CONTENT = ['json']
CELERY_TASK_SERIALIZER = 'json'
CELERY_RESULT_SERIALIZER = 'json'
CELERY_TIMEZONE = 'Australia/Melbourne'

# Celery Beat Schedule
CELERY_BEAT_SCHEDULE = {
    'generate-monthly-reports': {
        'task': 'apps.reporting.tasks.generate_monthly_reports',
        'schedule': crontab(day_of_month=1, hour=2),
    },
    'sync-ndis-data': {
        'task': 'apps.integrations.tasks.sync_ndis_data',
        'schedule': crontab(minute='*/30'),
    },
    'process-ndis-claims': {
        'task': 'apps.finances.tasks.process_ndis_claims',
        'schedule': crontab(minute='*/15'),
    },
}
```

### Task Examples
```python
# apps/finances/tasks.py
from celery import shared_task
from django.core.mail import send_mail
from .models import NDISClaim, Payment

@shared_task
def process_ndis_claims():
    """Process pending NDIS claims."""
    pending_claims = NDISClaim.objects.filter(status='pending')
    
    for claim in pending_claims:
        try:
            # Process claim logic here
            claim.status = 'processed'
            claim.processed_at = timezone.now()
            claim.save()
            
            # Send notification
            send_claim_processed_notification.delay(claim.id)
            
        except Exception as e:
            claim.status = 'error'
            claim.save()
            # Log error

@shared_task
def send_claim_processed_notification(claim_id):
    """Send notification when claim is processed."""
    try:
        claim = NDISClaim.objects.get(id=claim_id)
        # Send email notification
        send_mail(
            subject='NDIS Claim Processed',
            message=f'Your claim {claim.claim_number} has been processed.',
            from_email='noreply@ndisprovider.com',
            recipient_list=[claim.provider.contact_email],
        )
    except NDISClaim.DoesNotExist:
        pass
```

## Database Configuration

### PostgreSQL Settings
```python
# settings/base.py
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.postgresql',
        'NAME': os.environ.get('DB_NAME', 'ndis_provider_pro'),
        'USER': os.environ.get('DB_USER', 'ndis_user'),
        'PASSWORD': os.environ.get('DB_PASSWORD', ''),
        'HOST': os.environ.get('DB_HOST', 'localhost'),
        'PORT': os.environ.get('DB_PORT', '5432'),
        'OPTIONS': {
            'charset': 'utf8mb4',
        },
    }
}

# Database optimization
DATABASES['default']['CONN_MAX_AGE'] = 600
DATABASES['default']['OPTIONS']['init_command'] = "SET sql_mode='STRICT_TRANS_TABLES'"
```

### Redis Configuration
```python
# settings/base.py
CACHES = {
    'default': {
        'BACKEND': 'django_redis.cache.RedisCache',
        'LOCATION': os.environ.get('REDIS_URL', 'redis://localhost:6379/1'),
        'OPTIONS': {
            'CLIENT_CLASS': 'django_redis.client.DefaultClient',
        }
    }
}

# Session configuration
SESSION_ENGINE = 'django.contrib.sessions.backends.cache'
SESSION_CACHE_ALIAS = 'default'
```

## Security Configuration

### Security Settings
```python
# settings/production.py
SECURE_BROWSER_XSS_FILTER = True
SECURE_CONTENT_TYPE_NOSNIFF = True
SECURE_HSTS_SECONDS = 31536000
SECURE_HSTS_INCLUDE_SUBDOMAINS = True
SECURE_HSTS_PRELOAD = True
X_FRAME_OPTIONS = 'DENY'
SECURE_REFERRER_POLICY = 'strict-origin-when-cross-origin'

# HTTPS settings
SECURE_SSL_REDIRECT = True
SECURE_PROXY_SSL_HEADER = ('HTTP_X_FORWARDED_PROTO', 'https')

# Password validation
AUTH_PASSWORD_VALIDATORS = [
    {
        'NAME': 'django.contrib.auth.password_validation.UserAttributeSimilarityValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.MinimumLengthValidator',
        'OPTIONS': {
            'min_length': 12,
        }
    },
    {
        'NAME': 'django.contrib.auth.password_validation.CommonPasswordValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.NumericPasswordValidator',
    },
]
```

## Testing Configuration

### Test Settings
```python
# settings/testing.py
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.sqlite3',
        'NAME': ':memory:',
    }
}

# Use fast password hashing for tests
PASSWORD_HASHERS = [
    'django.contrib.auth.hashers.MD5PasswordHasher',
]

# Disable logging during tests
LOGGING = {
    'version': 1,
    'disable_existing_loggers': True,
}
```

### Test Examples
```python
# apps/participants/tests.py
from django.test import TestCase
from django.contrib.auth import get_user_model
from rest_framework.test import APITestCase
from rest_framework import status
from .models import Participant
from .serializers import ParticipantSerializer

class ParticipantModelTest(TestCase):
    def setUp(self):
        self.user = get_user_model().objects.create_user(
            username='testuser',
            email='test@example.com',
            password='testpass123'
        )
        self.provider = Provider.objects.create(
            name='Test Provider',
            ABN='12345678901',
            NDIS_number='NDIS001'
        )
        self.user.provider = self.provider
        self.user.save()

    def test_create_participant(self):
        participant = Participant.objects.create(
            NDIS_number='P001',
            first_name='John',
            last_name='Doe',
            provider=self.provider
        )
        self.assertEqual(participant.first_name, 'John')
        self.assertEqual(participant.provider, self.provider)

class ParticipantAPITest(APITestCase):
    def setUp(self):
        # Setup test data
        pass

    def test_list_participants(self):
        response = self.client.get('/api/v1/participants/')
        self.assertEqual(response.status_code, status.HTTP_200_OK)

    def test_create_participant(self):
        data = {
            'NDIS_number': 'P002',
            'first_name': 'Jane',
            'last_name': 'Smith',
        }
        response = self.client.post('/api/v1/participants/', data)
        self.assertEqual(response.status_code, status.HTTP_201_CREATED)
```

## Deployment Configuration

### Docker Configuration
```dockerfile
# Dockerfile
FROM python:3.11-slim

# Set environment variables
ENV PYTHONDONTWRITEBYTECODE=1
ENV PYTHONUNBUFFERED=1

# Set work directory
WORKDIR /app

# Install system dependencies
RUN apt-get update && apt-get install -y \
    gcc \
    postgresql-client \
    && rm -rf /var/lib/apt/lists/*

# Install Python dependencies
COPY requirements/production.txt /app/
RUN pip install -r production.txt

# Copy project
COPY . /app/

# Collect static files
RUN python manage.py collectstatic --noinput

# Run the application
CMD ["gunicorn", "--bind", "0.0.0.0:8000", "ndis_pro.wsgi:application"]
```

### Docker Compose
```yaml
# docker-compose.yml
version: '3.8'

services:
  web:
    build: .
    command: gunicorn --bind 0.0.0.0:8000 ndis_pro.wsgi:application
    volumes:
      - .:/app
      - static_volume:/app/static
      - media_volume:/app/media
    ports:
      - "8000:8000"
    depends_on:
      - db
      - redis
    environment:
      - DATABASE_URL=postgresql://ndis_user:ndis_pass@db:5432/ndis_provider_pro
      - REDIS_URL=redis://redis:6379/0

  db:
    image: postgres:15
    volumes:
      - postgres_data:/var/lib/postgresql/data
    environment:
      - POSTGRES_DB=ndis_provider_pro
      - POSTGRES_USER=ndis_user
      - POSTGRES_PASSWORD=ndis_pass

  redis:
    image: redis:7-alpine
    volumes:
      - redis_data:/data

  nginx:
    image: nginx:alpine
    volumes:
      - ./docker/nginx/nginx.conf:/etc/nginx/nginx.conf
      - static_volume:/app/static
      - media_volume:/app/media
    ports:
      - "80:80"
    depends_on:
      - web

volumes:
  postgres_data:
  redis_data:
  static_volume:
  media_volume:
```

## Development Workflow

### 1. Environment Setup
```bash
# Create virtual environment
python -m venv venv
source venv/bin/activate  # On Windows: venv\Scripts\activate

# Install dependencies
pip install -r requirements/development.txt

# Setup database
python manage.py migrate
python manage.py createsuperuser

# Run development server
python manage.py runserver
```

### 2. Code Quality Tools
```bash
# Install pre-commit hooks
pre-commit install

# Run linting
flake8 .
black .
isort .

# Run tests
python manage.py test
pytest

# Run coverage
coverage run --source='.' manage.py test
coverage report
```

### 3. Database Migrations
```bash
# Create migration
python manage.py makemigrations

# Apply migration
python manage.py migrate

# Show migration status
python manage.py showmigrations
```

## Performance Optimization

### Database Optimization
```python
# Use select_related and prefetch_related
participants = Participant.objects.select_related(
    'provider', 'coordinator'
).prefetch_related(
    'goals', 'service_plans'
)

# Use database indexes
class Participant(models.Model):
    NDIS_number = models.CharField(max_length=50, db_index=True)
    provider = models.ForeignKey(Provider, db_index=True)
    
    class Meta:
        indexes = [
            models.Index(fields=['provider', 'status']),
            models.Index(fields=['created_at']),
        ]
```

### Caching Strategy
```python
# Cache expensive queries
from django.core.cache import cache

def get_participant_stats(provider_id):
    cache_key = f'participant_stats_{provider_id}'
    stats = cache.get(cache_key)
    
    if stats is None:
        stats = Participant.objects.filter(
            provider_id=provider_id
        ).aggregate(
            total=Count('id'),
            active=Count('id', filter=Q(status='active')),
            inactive=Count('id', filter=Q(status='inactive'))
        )
        cache.set(cache_key, stats, 300)  # Cache for 5 minutes
    
    return stats
```

---

*This technical implementation plan provides a comprehensive guide for building the NDIS Provider Pro application using Python/Django framework. It covers all aspects from project structure to deployment configuration.*