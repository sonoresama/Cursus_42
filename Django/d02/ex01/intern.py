class Intern:
    name = "My name? I’m nobody, an intern, I have no name."

    class Coffee:
        def __str__(self) -> str:
            return ("This is the worst coffee you ever tasted.")

    def __init__(self, name=None) -> None:
        if (name == None):
            return
        self.name = name

    def __str__(self) -> str:
        return self.name

    def make_coffee(self) -> Coffee():
        return (self.Coffee())

    def work(self) -> Exception():
        raise Exception("I'm just an intern, I can't do work")

if __name__ == '__main__':
    none = Intern()
    titi = Intern("titi")
    cof = titi.make_coffee()
    try:
        print(none)
        print(titi)
        print(cof)
        none.work()
    except Exception as e:
        print(e);
