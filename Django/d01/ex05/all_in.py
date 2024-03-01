import sys

    #UTILITIES
def is_capital(capital_cities, states, capital):
    key_states = list(states.keys())
    for key, value in capital_cities.items():
        if value == capital:
            print(f"{value} is the capital of {key_states[list(capital_cities.values()).index(value)]}")
            return True
    return False

def is_state(capital_cities, states, state):
    for key, value in states.items():
        if key == state:
            print(f"{capital_cities[value]} is teh capital of {key}")
            return True
    return False

def parse_arg(arg):
    args = arg.split(',')
    clean_args = [item.strip() for item in args]
    return clean_args

    #MAIN FUNCTION
def all_in():
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
    if (len(sys.argv) != 2):
        return
    args = parse_arg(sys.argv[1])
    for strs in args:
        if not strs:
            continue
        if not is_capital(capital_cities, states, strs) and not is_state(capital_cities, states, strs):
            print(f"{strs} is neither a capital city nor a state")


if __name__ == '__main__':
    all_in()
