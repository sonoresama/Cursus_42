from django.shortcuts import render
from django.http import HttpResponse

def django(request):
    return render(request, 'ex01/django.html')

def affichage(request):
    return render(request, 'ex01/affichage.html')

def template(request):
    return render(request, 'ex01/template.html')

def index(request):
    return HttpResponse("FDP")
