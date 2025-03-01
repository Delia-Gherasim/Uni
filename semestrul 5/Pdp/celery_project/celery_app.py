from celery import Celery

app = Celery('timetable_generator', broker='redis://localhost:6379/0')

app.conf.update(
    result_backend='redis://localhost:6379/0',
    task_serializer='pickle',        
    result_serializer='pickle',
    accept_content=['pickle'],
)


import services.CeleryService 
