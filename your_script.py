from manim import *
import numpy as np

class FrogJump(Scene):
    def construct(self):
        heights = [30, 10, 60, 10, 60, 50]
        n = len(heights)
        dp = [-1] * n
        dp[0] = 0
        
        circles = []
        labels = []
        
        # Positioning stones (nodes)
        for i, h in enumerate(heights):
            pos = RIGHT * i * 1.5 + UP * (h / 20)
            circle = Circle(radius=0.3, color=BLUE).move_to(pos)
            label = Text(str(h), font_size=24).move_to(pos)
            circles.append(circle)
            labels.append(label)
            self.add(circle, label)
        
        self.wait(1)
        
        # Dynamic programming calculation and animation of jumps
        for ind in range(1, n):
            jump_one = dp[ind - 1] + abs(heights[ind] - heights[ind - 1])
            jump_two = float('inf')
            
            if ind > 1:
                jump_two = dp[ind - 2] + abs(heights[ind] - heights[ind - 2])
            
            dp[ind] = min(jump_one, jump_two)
            
            # Animating the frog's jumps
            start = circles[ind - 1]
            end = circles[ind]
            jump_arrow = Arrow(start.get_center(), end.get_center(), buff=0.1, color=GREEN)
            self.play(Create(jump_arrow), run_time=0.8)
            self.wait(0.5)
        
        # Display final minimum cost
        final_text = Text(f"Minimum Cost: {dp[-1]}", font_size=30).to_edge(DOWN)
        self.play(Write(final_text))
        self.wait(2)
