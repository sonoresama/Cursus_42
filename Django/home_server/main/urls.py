from django.urls import path
from . import views

urlpatterns = [
    path("<str:directory>/download_zip", views.download_zip, name="download_zip"),
    path("", views.index, name="index"),
]
