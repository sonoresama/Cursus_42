from  django import forms

class History(forms.Form):
    history_text = forms.CharField(label="History", max_length=100)
