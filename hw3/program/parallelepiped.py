import random
from shape import *
# ----------------------------------------------


class Parallelepiped(Shape):
    def __init__(self):
        self.a = 0
        self.b = 0
        self.c = 0
        self.material_density = 0.0

    def get_figure_from_file(self, data, i):
        self.material_density = float(data[i])
        self.a = int(data[i + 1])
        self.b = int(data[i + 2])
        self.c = int(data[i + 3])

    def get_random_figure(self):
        self.a = random.randint(1, 101)
        self.b = random.randint(1, 101)
        self.c = random.randint(1, 101)
        self.material_density = random.uniform(1, 10001)

    def surface_area(self):
        return float(2 * (self.a * self.b + self.b * self.c + self.a * self.c))

    def write(self, output):
        output.write("It is Parallelepiped: First edge: a = {}. Second edge: b = {}. Third edge: c = {}. "
                     "Surface area = {}. Material density = {}"
                     .format(self.a, self.b, self.c, self.surface_area(), self.material_density))
