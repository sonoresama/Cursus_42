import logging
from django.shortcuts import render, redirect
from django.http import HttpResponse
from django.conf import settings
from .forms import History

def history(request):
    file_log = open(settings.LOG_PATH, 'r')
    history = [line for line in file_log.readlines()]
    logger = logging.getLogger('history')
    if request.method == 'POST':
        form = History(request.POST)
        if form.is_valid():
            logger.info(form.cleaned_data['history_text'])
        return redirect('/ex02/')
    else:
            form = History()
    context = {"form":form, "history":history}
    return render(request, 'ex02/history.html', context)
