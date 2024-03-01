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
    keys_list = list(states.keys())
    if len(sys.argv) != 2:
        return
    for key, value in capital_cities.items():
        if value == sys.argv[1]:
            print(keys_list[list(states.values()).index(key)])
            return
    print("Unknown capital city")


if __name__ == '__main__':
    capital_city()
