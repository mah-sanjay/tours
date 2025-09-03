# NDIS Provider Pro - Entity-Relationship Diagrams

## ER Diagram Notation
- **Entity**: Rectangle representing a table/object
- **Attribute**: Oval representing a field/property
- **Relationship**: Diamond representing connections between entities
- **Cardinality**: Numbers showing relationship quantities (1:1, 1:N, M:N)

## 1. Core System ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│    Provider     │         │      User       │         │    Location     │
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: provider_id │◄────────┤ PK: user_id     │◄────────┤ PK: location_id│
│ name            │    1:N  │ username        │    1:N  │ name            │
│ ABN             │         │ email           │         │ address         │
│ NDIS_number     │         │ password_hash   │         │ phone           │
│ registration_date│         │ first_name      │         │ manager_id      │
│ status          │         │ last_name       │         │ created_at      │
│ created_at      │         │ role            │         │ updated_at      │
│ updated_at      │         │ provider_id     │         └─────────────────┘
│                 │         │ location_id     │
│                 │         │ is_active       │
│                 │         │ last_login      │
│                 │         │ created_at      │
│                 │         │ updated_at      │
└─────────────────┘         └─────────────────┘
         │                           │
         │                           │
         │ 1:N                       │ 1:N
         │                           │
         ▼                           ▼
┌─────────────────┐         ┌─────────────────┐
│   User_Role     │         │   Permission    │
├─────────────────┤         ├─────────────────┤
│ PK: role_id     │         │ PK: permission_id│
│ name            │         │ name            │
│ description     │         │ description     │
│ provider_id     │         │ module          │
│ created_at      │         │ action          │
│ updated_at      │         │ created_at      │
└─────────────────┘         └─────────────────┘
         │                           │
         │ M:N                       │ M:N
         │                           │
         ▼                           ▼
┌─────────────────┐         ┌─────────────────┐
│ User_Role_Link  │         │ Role_Permission │
├─────────────────┤         ├─────────────────┤
│ PK: link_id     │         │ PK: link_id     │
│ user_id         │         │ role_id         │
│ role_id         │         │ permission_id   │
│ assigned_at     │         │ assigned_at     │
└─────────────────┘         └─────────────────┘
```

## 2. Participant Management ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│   Participant   │         │   Participant   │         │   Participant   │
│                 │         │     Goal        │         │   Document      │
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: participant_id│        │ PK: goal_id     │         │ PK: document_id│
│ NDIS_number     │◄────────┤ participant_id  │◄────────┤ participant_id  │
│ first_name      │    1:N  │ title           │    1:N  │ filename        │
│ last_name       │         │ description     │         │ file_path       │
│ date_of_birth  │         │ target_date     │         │ file_type       │
│ gender          │         │ status          │         │ file_size       │
│ address         │         │ progress        │         │ uploaded_by     │
│ phone           │         │ created_at      │         │ uploaded_at     │
│ email           │         │ updated_at      │         │ created_at      │
│ emergency_contact│         └─────────────────┘         │ updated_at      │
│ medical_info    │                   │                 └─────────────────┘
│ cultural_info   │                   │
│ provider_id     │                   │ 1:N
│ coordinator_id  │                   │
│ created_at      │                   ▼
│ updated_at      │         ┌─────────────────┐
└─────────────────┘         │   Goal_Progress │
         │                  ├─────────────────┤
         │ 1:N              │ PK: progress_id │
         │                  │ goal_id         │
         ▼                  │ date            │
┌─────────────────┐         │ notes           │
│   Service_Plan  │         │ created_at      │
├─────────────────┤         └─────────────────┘
│ PK: plan_id     │
│ participant_id  │
│ title           │
│ description     │
│ start_date      │
│ end_date        │
│ status          │
│ created_at      │
│ updated_at      │
└─────────────────┘
         │
         │ 1:N
         │
         ▼
┌─────────────────┐
│   Service_Item  │
├─────────────────┤
│ PK: item_id     │
│ plan_id         │
│ service_type    │
│ description     │
│ frequency       │
│ duration        │
│ worker_id       │
│ created_at      │
│ updated_at      │
└─────────────────┘
```

## 3. Financial Management ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│   NDIS_Plan     │         │   NDIS_Claim    │         │   Payment       │
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: plan_id     │◄────────┤ PK: claim_id    │◄────────┤ PK: payment_id │
│ participant_id  │    1:N  │ plan_id         │    1:N  │ claim_id        │
│ plan_number     │         │ claim_number    │         │ amount          │
│ start_date      │         │ claim_date      │         │ payment_date    │
│ end_date        │         │ total_amount    │         │ payment_method  │
│ total_budget    │         │ status          │         │ reference       │
│ status          │         │ submitted_at    │         │ created_at      │
│ created_at      │         │ processed_at    │         │ updated_at      │
│ updated_at      │         │ created_at      │         └─────────────────┘
└─────────────────┘         │ updated_at      │
         │                  └─────────────────┘
         │ 1:N                       │
         │                           │ 1:N
         ▼                           ▼
┌─────────────────┐         ┌─────────────────┐
│   Budget_Category│         │   Claim_Item    │
├─────────────────┤         ├─────────────────┤
│ PK: category_id │         │ PK: item_id     │
│ plan_id         │         │ claim_id        │
│ category_name   │         │ service_id      │
│ allocated_budget│         │ quantity        │
│ spent_amount    │         │ unit_rate       │
│ remaining_budget│         │ total_amount    │
│ created_at      │         │ support_category│
│ updated_at      │         │ created_at      │
└─────────────────┘         │ updated_at      │
         │                  └─────────────────┘
         │ 1:N                       │
         │                           │ 1:N
         ▼                           ▼
┌─────────────────┐         ┌─────────────────┐
│   Budget_Transaction│       │   Invoice       │
├─────────────────┤         ├─────────────────┤
│ PK: transaction_id│        │ PK: invoice_id  │
│ category_id     │         │ claim_item_id   │
│ amount          │         │ invoice_number  │
│ transaction_type│         │ amount          │
│ description     │         │ due_date        │
│ date            │         │ status          │
│ created_at      │         │ sent_date       │
│ updated_at      │         │ paid_date       │
└─────────────────┘         │ created_at      │
                            │ updated_at      │
                            └─────────────────┘
```

## 4. Workforce Management ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│     Worker      │         │   Qualification │         │     Training    │
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: worker_id   │◄────────┤ PK: qual_id     │◄────────┤ PK: training_id│
│ user_id         │    1:N  │ worker_id       │    1:N  │ worker_id       │
│ employee_number │         │ qualification_type│        │ training_type   │
│ hire_date       │         │ institution     │         │ institution     │
│ status          │         │ completion_date │         │ completion_date │
│ hourly_rate     │         │ expiry_date     │         │ expiry_date     │
│ skills          │         │ certificate_no  │         │ certificate_no  │
│ availability    │         │ created_at      │         │ created_at      │
│ created_at      │         │ updated_at      │         │ updated_at      │
│ updated_at      │         └─────────────────┘         └─────────────────┘
└─────────────────┘
         │
         │ 1:N
         │
         ▼
┌─────────────────┐
│   Work_Schedule │
├─────────────────┤
│ PK: schedule_id │
│ worker_id       │
│ date            │
│ start_time      │
│ end_time        │
│ break_start     │
│ break_end       │
│ location_id     │
│ created_at      │
│ updated_at      │
└─────────────────┘
         │
         │ 1:N
         │
         ▼
┌─────────────────┐
│   Time_Record   │
├─────────────────┤
│ PK: record_id   │
│ schedule_id     │
│ clock_in_time   │
│ clock_out_time  │
│ break_start     │
│ break_end       │
│ total_hours     │
│ location        │
│ created_at      │
│ updated_at      │
└─────────────────┘
```

## 5. Service Delivery ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│     Service     │         │   Service_Delivery│        │   Service_Outcome│
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: service_id  │◄────────┤ PK: delivery_id │◄────────┤ PK: outcome_id  │
│ service_type    │    1:N  │ service_id      │    1:N  │ delivery_id     │
│ description     │         │ worker_id       │         │ outcome_type    │
│ duration        │         │ participant_id  │         │ description     │
│ rate            │         │ scheduled_date  │         │ measurement     │
│ support_category│         │ actual_date     │         │ notes           │
│ created_at      │         │ start_time      │         │ created_at      │
│ updated_at      │         │ end_time        │         │ updated_at      │
└─────────────────┘         │ status          │         └─────────────────┘
         │                  │ notes           │
         │ 1:N              │ created_at      │
         │                  │ updated_at      │
         ▼                  └─────────────────┘
┌─────────────────┐                   │
│   Service_Note  │                   │ 1:N
├─────────────────┤                   │
│ PK: note_id     │                   ▼
│ service_id      │         ┌─────────────────┐
│ note_type       │         │   Service_Photo │
│ content         │         ├─────────────────┤
│ created_by      │         │ PK: photo_id    │
│ created_at      │         │ delivery_id     │
│ updated_at      │         │ filename        │
└─────────────────┘         │ file_path       │
                            │ caption         │
                            │ uploaded_at     │
                            │ created_at      │
                            │ updated_at      │
                            └─────────────────┘
```

## 6. Quality & Compliance ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│   NDIS_Standard │         │   Compliance    │         │   Incident      │
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: standard_id │◄────────┤ PK: compliance_id│        │ PK: incident_id │
│ standard_name   │    1:N  │ standard_id     │         │ participant_id  │
│ description     │         │ provider_id     │         │ worker_id       │
│ category        │         │ status          │         │ incident_type   │
│ version         │         │ last_audit_date │         │ severity        │
│ effective_date  │         │ next_audit_date │         │ description     │
│ created_at      │         │ notes           │         │ incident_date   │
│ updated_at      │         │ created_at      │         │ location        │
└─────────────────┘         │ updated_at      │         │ status          │
         │                  └─────────────────┘         │ reported_at     │
         │ 1:N                       │                  │ created_at      │
         │                           │ 1:N              │ updated_at      │
         ▼                           ▼                  └─────────────────┘
┌─────────────────┐         ┌─────────────────┐                   │
│   Standard_Requirement│    │   Audit_Record  │                   │ 1:N
├─────────────────┤         ├─────────────────┤                   │
│ PK: requirement_id│        │ PK: audit_id    │                   │
│ standard_id     │         │ compliance_id   │                   ▼
│ requirement_text│         │ audit_date      │         ┌─────────────────┐
│ priority        │         │ auditor         │         │   Incident_Action│
│ created_at      │         │ findings        │         ├─────────────────┤
│ updated_at      │         │ recommendations │         │ PK: action_id   │
└─────────────────┘         │ created_at      │         │ incident_id     │
                            │ updated_at      │         │ action_type     │
                            └─────────────────┘         │ description     │
                                                        │ assigned_to     │
                                                        │ due_date        │
                                                        │ status          │
                                                        │ completed_date  │
                                                        │ created_at      │
                                                        │ updated_at      │
                                                        └─────────────────┘
```

## 7. Reporting & Analytics ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│     Report      │         │   Report_Template│        │   Dashboard     │
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: report_id   │◄────────┤ PK: template_id │◄────────┤ PK: dashboard_id│
│ template_id     │    1:N  │ name            │    1:N  │ template_id     │
│ name            │         │ description     │         │ name            │
│ parameters      │         │ query           │         │ layout          │
│ generated_date  │         │ parameters      │         │ user_id         │
│ status          │         │ created_by      │         │ is_default      │
│ file_path       │         │ created_at      │         │ created_at      │
│ created_at      │         │ updated_at      │         │ updated_at      │
│ updated_at      │         └─────────────────┘         └─────────────────┘
└─────────────────┘
         │
         │ 1:N
         │
         ▼
┌─────────────────┐
│   Report_Data   │
├─────────────────┤
│ PK: data_id     │
│ report_id       │
│ data_type       │
│ data_value      │
│ data_date       │
│ created_at      │
│ updated_at      │
└─────────────────┘
         │
         │ 1:N
         │
         ▼
┌─────────────────┐
│   Report_Export │
├─────────────────┤
│ PK: export_id   │
│ report_id       │
│ export_format   │
│ file_path       │
│ exported_by     │
│ exported_at     │
│ created_at      │
│ updated_at      │
└─────────────────┘
```

## 8. Mobile Application ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│   Mobile_Device│         │   Offline_Data  │         │   Sync_Log      │
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: device_id   │◄────────┤ PK: offline_id  │◄────────┤ PK: sync_id     │
│ user_id         │    1:N  │ device_id       │    1:N  │ device_id       │
│ device_type     │         │ data_type       │         │ sync_type       │
│ device_token    │         │ data_id         │         │ status          │
│ last_sync       │         │ data_content    │         │ start_time      │
│ is_active       │         │ created_at      │         │ end_time        │
│ created_at      │         │ updated_at      │         │ records_synced  │
│ updated_at      │         └─────────────────┘         │ errors          │
└─────────────────┘                                     │ created_at      │
         │                                               │ updated_at      │
         │ 1:N                                           └─────────────────┘
         │
         ▼
┌─────────────────┐
│   Location_Log  │
├─────────────────┤
│ PK: log_id      │
│ device_id       │
│ latitude        │
│ longitude       │
│ accuracy        │
│ timestamp       │
│ created_at      │
│ updated_at      │
└─────────────────┘
```

## 9. System Integration ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│   External_System│        │   API_Endpoint  │         │   Integration_Log│
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: system_id   │◄────────┤ PK: endpoint_id │◄────────┤ PK: log_id      │
│ name            │    1:N  │ system_id       │    1:N  │ endpoint_id     │
│ system_type     │         │ endpoint_url    │         │ request_data    │
│ base_url        │         │ method          │         │ response_data   │
│ api_key         │         │ headers         │         │ status_code     │
│ status          │         │ rate_limit      │         │ response_time   │
│ created_at      │         │ is_active       │         │ error_message   │
│ updated_at      │         │ created_at      │         │ created_at      │
└─────────────────┘         │ updated_at      │         │ updated_at      │
         │                  └─────────────────┘         └─────────────────┘
         │ 1:N                       │
         │                           │ 1:N
         ▼                           ▼
┌─────────────────┐         ┌─────────────────┐
│   Webhook       │         │   Data_Mapping  │
├─────────────────┤         ├─────────────────┤
│ PK: webhook_id  │         │ PK: mapping_id  │
│ system_id       │         │ endpoint_id     │
│ webhook_url     │         │ source_field    │
│ events          │         │ target_field    │
│ secret_key      │         │ transformation  │
│ is_active       │         │ is_required     │
│ created_at      │         │ created_at      │
│ updated_at      │         │ updated_at      │
└─────────────────┘         └─────────────────┘
```

## 10. Security & Audit ER Diagram

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────┐
│   User_Session  │         │   Access_Log    │         │   Security_Event│
├─────────────────┤         ├─────────────────┤         ├─────────────────┤
│ PK: session_id  │◄────────┤ PK: log_id      │◄────────┤ PK: event_id    │
│ user_id         │    1:N  │ user_id         │    1:N  │ user_id         │
│ session_token   │         │ action          │         │ event_type      │
│ ip_address      │         │ resource        │         │ description     │
│ user_agent      │         │ timestamp       │         │ severity        │
│ login_time      │         │ success         │         │ ip_address      │
│ logout_time     │         │ created_at      │         │ user_agent      │
│ is_active       │         │ updated_at      │         │ timestamp       │
│ created_at      │         └─────────────────┘         │ created_at      │
│ updated_at      │                                     │ updated_at      │
└─────────────────┘                                     └─────────────────┘
         │
         │ 1:N
         │
         ▼
┌─────────────────┐
│   Login_Attempt │
├─────────────────┤
│ PK: attempt_id  │
│ session_id      │
│ username        │
│ ip_address      │
│ success         │
│ failure_reason  │
│ timestamp       │
│ created_at      │
│ updated_at      │
└─────────────────┘
```

## Database Relationships Summary

### One-to-Many (1:N) Relationships
- **Provider** → **User** (One provider has many users)
- **Provider** → **Location** (One provider has many locations)
- **User** → **Location** (One user belongs to one location)
- **Participant** → **Goal** (One participant has many goals)
- **Participant** → **Document** (One participant has many documents)
- **NDIS_Plan** → **Budget_Category** (One plan has many budget categories)
- **NDIS_Claim** → **Claim_Item** (One claim has many items)
- **Worker** → **Qualification** (One worker has many qualifications)
- **Worker** → **Work_Schedule** (One worker has many schedules)
- **Service** → **Service_Delivery** (One service has many deliveries)

### Many-to-Many (M:N) Relationships
- **User** ↔ **Role** (Users can have multiple roles, roles can have multiple users)
- **Role** ↔ **Permission** (Roles can have multiple permissions, permissions can belong to multiple roles)
- **Worker** ↔ **Skill** (Workers can have multiple skills, skills can belong to multiple workers)
- **Service** ↔ **Support_Category** (Services can belong to multiple categories)

### Key Design Principles
1. **Normalization**: Tables are normalized to reduce redundancy
2. **Referential Integrity**: Foreign keys maintain data consistency
3. **Audit Trail**: Created_at and updated_at fields track changes
4. **Soft Deletes**: Status fields instead of hard deletes
5. **Flexible Permissions**: Role-based access control system
6. **Scalability**: Design supports multiple providers and locations

---

*These ER diagrams provide a comprehensive view of the database structure for the NDIS Provider Pro application. They show the relationships between entities and help developers understand the data model for implementation.*