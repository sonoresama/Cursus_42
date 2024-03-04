class HotBeverage:
    price = 0.30
    name = "hot beverage"
    def description(self) -> str:
        return ("Just some hot water in a cup")

    def __str__(self) -> str:
        string = ""
        string = f"name : {self.name}\n"
        string += f"price : {self.price:.2f}\n"
        string += f"descrition : {self.description()}"
        return (string)

class Coffee(HotBeverage):
    price = 0.40
    name = "coffee"
    def description(self) -> str:
        return ("A coffee to stay awake")

class Tea(HotBeverage):
    name = "tea"

class Chocolate(HotBeverage):
    price = 0.50
    name = "chocolate"
    def description(self) -> str :
        return ("Chocolate, sweet chocolate...")

if __name__ == '__main__':
    hb = HotBeverage()
    cof = Coffee()
    te = Tea()
    ch = Chocolate()
    print(hb)
    print(cof)
    print(te)
    print(ch)

