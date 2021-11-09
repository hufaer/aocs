import math
import random
from shape import *
# ----------------------------------------------


class Sphere(Shape):
    def __init__(self):
        self.r = 0
        self.material_density = 0.0

    def get_figure_from_file(self, data, i):
        self.material_density = float(data[i])
        self.r = int(data[i + 1])

    def get_random_figure(self):
        self.r = random.randint(1, 101)
        self.material_density = random.uniform(1, 10001)

    def surface_area(self):
        return float(4 * math.pi * math.pow(self.r, 2))

    def write(self, output):
        output.write("It is Sphere: Radius: r = {}. "
                     "Surface area = {}. Material density = {}"
                     .format(self.r, self.surface_area(), self.material_density))
