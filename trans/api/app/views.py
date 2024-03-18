from django.http import HttpResponse
from rest_framework.decorators import api_view
from rest_framework.response import Response


@api_view(['GET', 'POST'])
def login(request):
    if request.method == 'POST':
        print(request.data)
        print(type(request.data))
        return Response({"reponse" : "OK"})
    return Response({"reponse" : "FDP"})

def index():
    return HttpResponse("HELLO")

