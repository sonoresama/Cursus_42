from django.urls import path
from . import views

urlpatterns = [
    path("django/", views.django, name="django"),
    path("affichage/", views.affichage, name="affichage"),
    path("template/", views.template, name="template"),
    path("", views.index, name="index"),
]
