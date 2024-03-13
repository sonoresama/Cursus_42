from django.shortcuts import render
from django.http import HttpResponse
import os
import zipfile

def index(request):
    m_content = 'main/static/media/music'
    i_content = 'main/static/media/image'
    d_content = 'main/static/media/document'
    music = os.listdir(m_content)
    image = os.listdir(i_content)
    document = os.listdir(d_content)
        #Gerer les retours d'erreur

    text = "\"Mets toi en valeur, mais n’oublie pas tes valeurs.\""
    context = {
        'document' : document,
        'music' : music,
        'image' : image,
        'banner_text' : text,
    }
    return render(request, 'main/index.html', context)

def download_zip(request, directory):
    static_path = 'main/static/'
    root_path = static_path + directory
    zip_file_path = static_path + directory + '-all.zip'
    with zipfile.ZipFile(zip_file_path, 'w') as zip_object:
        for folder_name, sub_folders, file_names in os.walk(root_path):
            for filename in file_names:
                file_path = os.path.join(folder_name, filename)
                zip_object.write(file_path, os.path.basename(file_path))
                print(f"Added the file {file_path}")

    with open(zip_file_path, 'rb') as opened_file:
        response = HttpResponse(
            opened_file.read(),
            headers={
                "Content-Type" : 'application/zip',
                "Content-Disposition" : f'attachement; filename="{directory}-all.zip"',
            },
        )
    os.remove(zip_file_path)
    return (response)

if __name__ == '__main__':
    pass
