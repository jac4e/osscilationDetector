# Oscillation detector
## Goal
Measure the oscillations of a pendulum and produce a value for period.
## Parts
- Arduino UNO 16MHz
- Laser diode
- Photo resistor
## Setup
A laser is pointed at a box with a translucent white window acting to diffuse the laser light. Behind this window, there is a photo resistor meant to detect the laser beam. The pendulum then swings between the box and the laser, interrupted the beam as it passes the reference point. 

To properly setup the device, the pendulum was placed and left to return to its equilibrium position. Afterwards the laser was placed such that the laser beam is perpendicular to the back surface of the pendulum, aiming at the center between two holes.

## Method
When the laser is first interrupted on the forward swing, the time in milliseconds from the start of the script is recorded as t_1, then a t_2 is recorded when the laser is no longer blocked. On the backwards swing, a similar procedure occurs but for a t_3 and t_4. The period is then calculated using the following equation

<img src="https://latex.codecogs.com/svg.latex?t%20%3D%202%28%28t_3%20&plus;%20%5Cfrac%7Bt_4-t_3%7D%7B2%7D%29-%28t_1%20&plus;%20%5Cfrac%7Bt_2-t_1%7D%7B2%7D%29%29" />

where t is the period and <img src="https://latex.codecogs.com/svg.latex?t_n%20&plus;%20%5Cfrac%7Bt_%7Bn&plus;1%7D-t_n%7D%7B2%7D"/> represents the time from the start of the script to approximetly the point at which the laser is on the vertical axis of the pendulum. This can be simplified to
<img src="https://latex.codecogs.com/svg.latex?t%3D%28t_3&plus;t_4%29-%28t_1&plus;t_2%29"/>
This is repeated 5 times, then the average period is calculated and sent over serial which can then be viewed on a computer using a serial monitor.
## Uncertainty
Since the photo resistor is polled every 100 $\mu\text{s}$, uncertainty produced by this process is negligible. The uncertainty in each time measurement is 0.5ms as the function used to record time only reports in ms, meaning the smallest unit is 1ms. The period is then assumed to have random error, resulting in a Gaussian distribution, so period and its uncertainty is calculated from the mean and standard deviation of multiple recordings for the same pendulum configuration.
