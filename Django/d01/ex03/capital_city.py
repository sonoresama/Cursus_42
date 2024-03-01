import sys

def capital_city():
    states = {
        "Oregon" : "OR",
        "Alabama" : "AL",
        "New Jersey": "NJ",
        "Colorado" : "CO"
    }
    capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
    }
    if len(sys.argv) != 2:
        return
    if not sys.argv[1] in states:
        print("Unknown state")
        return
    print(capital_cities[states[sys.argv[1]]])


if __name__ == '__main__':
    capital_city()
