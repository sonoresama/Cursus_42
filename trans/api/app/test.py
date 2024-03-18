def test(func):
     def wrapper():
             print ("coco")
             func()
             print ("cucu")
     return wrapper

@test
def pouet():
    print("turlututu")

pouet()
