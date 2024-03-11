from django.shortcuts import render
from django.http import HttpResponse
import os

def main():
    m_content = 'static/music'
    i_content = 'static/image'
    d_content = 'static/document'
    music = os.listdir(m_content)
    image = os.listdir(i_content)
    document = os.listdir(d_content)
    print(music)

def index(request):
    m_content = 'main/static/music'
    i_content = 'main/static/image'
    d_content = 'main/static/document'
    music = os.listdir(m_content)
    image = os.listdir(i_content)
    document = os.listdir(d_content)
    print(music)
    context = {
        'document' : document,
        'music' : music,
        'image' : image,
    }
    return render(request, 'main/index.html', context)

if __name__ == '__main__':
    main()
