def factorize_numbers(file_path):
    with open(file_path, 'r') as file:
        numbers = file.read().splitlines()

    for number in numbers:
        n = int(number)
        factors = find_factors(n)
        print(f"{n} = {factors}")

file_path = 'tests.txt'

factorize_numbers(file_path)
