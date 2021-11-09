from sphere import *
from tetrahedron import *
from parallelepiped import *
# ----------------------------------------------


class Container:
    def __init__(self):
        self.store = []

    def get_figures_from_file(self, data):
        i = 0
        shape = 0
        while i < len(data):
            fig = int(data[i])
            if fig == 1:
                shape = Parallelepiped()
                shape.get_figure_from_file(data, i+1)
                i += 3
            elif fig == 2:
                shape = Sphere()
                shape.get_figure_from_file(data, i+1)
                i += 1
            elif fig == 3:
                shape = Tetrahedron()
                shape.get_figure_from_file(data, i+1)
                i += 1
            i += 2
            self.store.append(shape)

    def get_random_figures(self, count):
        i = 0
        shape = 0
        while i < count:
            fig = random.randint(1, 4)
            if fig == 1:
                shape = Parallelepiped()
                shape.get_random_figure()
            if fig == 2:
                shape = Sphere()
                shape.get_random_figure()
            if fig == 3:
                shape = Tetrahedron()
                shape.get_random_figure()
            i += 1
            self.store.append(shape)

    def write(self, output):
        output.write("Container is store {} shapes:\n"
                     .format(len(self.store)))
        for shape in self.store:
            shape.write(output)
            output.write("\n")

    def processing_var_21(self, output):
        sum = 0.0
        for shape in self.store:
            sum += shape.surface_area()
        mean = sum / len(self.store)
        output.write("Arithmetic mean: {}\n".format(mean))
        output.write("Surface areas processed:\n")
        for shape in self.store:
            if shape.surface_area() >= mean:
                shape.write(output)
                output.write("\n")
        output.write("\n")
