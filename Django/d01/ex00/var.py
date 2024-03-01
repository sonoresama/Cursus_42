def my_var():
    integer: int = 42
    string: str = "42"
    long_string: str = "quarante-deux"
    floating: float = 42.0
    boolean: bool = True
    listing: list = [42]
    dico: dict = {42:42}
    tu: tuple = (42,)
    seto: set = (set())

    print(f"{integer} est de type {type(integer)}")
    print(f"{string} est de type {type(string)}")
    print(f"{long_string} est de type {type(long_string)}")
    print(f"{floating} est de type {type(floating)}")
    print(f"{boolean} est de type {type(boolean)}")
    print(f"{listing} est de type {type(listing)}")
    print(f"{dico} est de type {type(dico)}")
    print(f"{tu} est de type {type(tu)}")
    print(f"{seto} est de type {type(seto)}")

if __name__ == '__main__':
    my_var()
