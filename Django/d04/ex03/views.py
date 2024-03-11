from django.shortcuts import render
from django.http import HttpResponse

context = {
    'range' : range(20, 70),
}

def index(request):
    return render(request, 'ex03/index.html', context)
