import math
from matplotlib import pyplot as plt

def calculate_derivated_value(sigma,phi_X):
    derivative_wrt_phi = math.degrees(1 / math.cos(math.radians(phi_X))**2) * sigma
    return derivative_wrt_phi

def calculate_shear_strength(C,sigma,phi_X):
    T = C + math.tan(math.radians(phi_X)) * sigma
    return T


def newton_raphson(C,sigma,phi_X):
    iteration_count = 0
    angles = [phi_X]
    strengths = [] 
    old_X = phi_X
    first_strength = calculate_shear_strength(C,sigma,old_X)
    strengths.append(first_strength)
    new_X = old_X -first_strength/ calculate_derivated_value(sigma,old_X)
    
    while abs(new_X - old_X) > 1e-9:  # Use a small threshold as a stopping criterion
        iteration_count+=1
        old_X = new_X
        angles.append(old_X)
        next_strength = calculate_shear_strength(C,sigma,old_X)
        strengths.append(next_strength)
        new_X = old_X -  next_strength/ calculate_derivated_value(sigma,old_X)
        

    return new_X,iteration_count,angles,strengths


if __name__ == '__main__':

    C = float(input('Effective Cohesion: '))
    
    sigma = float(input('Effective Stress: '))

    phi_X= float(input('Internal Friction Angle: '))

    x_final,iteration_count,angles,strengths = newton_raphson(C,sigma,phi_X)
    
    angles = [angles[i] for i in range(len(angles)) if angles[i] > 0 if angles[i] < 50 ]
    strengths = [strengths[i] for i in range(len(angles)) if angles[i] > 0 if angles[i] < 50]
    # Plot the data
    plt.plot(angles, strengths)

    # # Customize the plot
    plt.xlabel('Angles (Degrees)')
    plt.ylabel('Shear Strength(T)')
    plt.title('Angle vs Shear Strength(T)')

    # # Display the plot
    plt.show()

    print(f"X is found to be {x_final} in {iteration_count} iterations...")

