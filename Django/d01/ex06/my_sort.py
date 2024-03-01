
def my_sort():
    d = {
        'Hendrix' : '1942',
        'Allman' : '1946',
        'King' : '1925',
        'Clapton' : '1945',
        'Johnson' : '1911',
        'Berry' : '1926',
        'Vaughan' : '1954',
        'Cooder' : '1947',
        'Page' : '1944',
        'Richards' : '1943',
        'Hammett' : '1962',
        'Cobain' : '1967',
        'Garcia' : '1942',
        'Beck' : '1944',
        'Santana' : '1947',
        'Ramone' : '1948',
        'White' : '1975',
        'Frusciante': '1970',
        'Thompson' : '1949',
        'Burton' : '1939'}
    ordered = []
    values_list = list(d.values())
    keys_list = list(d.keys())

    while len(d) != 0:
        min = list(d.items())[0]
        for key, value in d.items():
            if value < min[1]:
                min = (key, value)
            elif value == min[1] and key < min[0]:
                min = (key, value)
        d.pop(min[0])
        ordered.append(min)
    for i in ordered:
        print(i[0])



if __name__ == '__main__':
    my_sort()
