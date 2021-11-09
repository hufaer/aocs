import math
import random
from shape import *
# ----------------------------------------------


class Tetrahedron(Shape):
    def __init__(self):
        self.a = 0
        self.material_density = 0.0

    def get_figure_from_file(self, data, i):
        self.material_density = float(data[i])
        self.a = int(data[i + 1])

    def get_random_figure(self):
        self.a = random.randint(1, 101)
        self.material_density = random.uniform(1, 10001)

    def surface_area(self):
        return math.sqrt(3) * math.pow(self.a, 2)

    def write(self, output):
        output.write("It is Regular Tetrahedron: Edge length: a = {}. "
                     "Surface area = {}. Material density = {}"
                     .format(self.a, self.surface_area(), self.material_density))
