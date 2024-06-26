"""
Source code based on Arbalet source in github: http://github.com/arbalet-project
"""

import random
from arbalet.core import Application, Rate
from .generators import gen_random_flashing, gen_sweep_async, gen_sweep_rand


class ColorDemo(Application):
    generators = [gen_random_flashing, gen_sweep_async, gen_sweep_rand, ]

    def __init__(self, parser, animations):
        Application.__init__(self, parser)
        config = animations[self.args.type]
        self.durations = [int(config['dur_min']*config['rate']), int(config['dur_max']*config['rate'])]
        self.rate = Rate(config['rate'])
        self.colors = config['colors']
        self.generator = self.generators[config['generator_id']]

    def run(self):
        # Construct all pixel generators
        generators = []
        for h in range(self.height):
            line = []
            for w in range(self.width):
                duration = random.randrange(0, self.durations[1]-self.durations[0])
                line.append(self.generator(self.durations[0], int(2/self.rate.sleep_dur), duration, self.colors))
            generators.append(line)

        # Browse all pixel generators at each time
        while True:
            with self.model:
                for h in range(self.height):
                    for w in range(self.width):
                        try:
                            color = next(generators[h][w])
                        except StopIteration:
                            pass
                        else:
                            self.model.set_pixel(h, w, color)
            self.rate.sleep()