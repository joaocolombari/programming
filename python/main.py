##
# Main python code from preparation Week 1 IOT
# Joao Colombari 
# OCT, 31, 2023
##

from psuedoSensor import PseudoSensor

ps = PseudoSensor()

for i in range(30):

    h,t = ps.generate_values()

    print("i ",i)

    print("H ",h)

    print("T ",t)