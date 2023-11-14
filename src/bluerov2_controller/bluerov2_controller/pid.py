#!/usr/bin/env python3
import numpy as np

def deg2rad(deg):   
    """Convert [0-360]deg to [-pi,pi]rad => [180,360]deg ~ [-pi,0]rad  ,  [0,180]deg ~ [0,pi]rad
       
    Input:
    ------
    deg: int
    """    
    if deg in range(0,181):
        return (deg * np.pi) / 180 
    if deg in range(181,361):
        return ((deg - 360) * np.pi) / 180
    
    print(f"Der Fehler ist {deg}")

def sawtooth (x):
    """Deal with 2*PI modulo
    
    Input:
    ------
    x: rad 
    """
    return (x+np.pi)%(2*np.pi)-np.pi      

def saturation(pwm, pwm_neutral, pwm_max):     
    """Saturate command
        
    Input:
    ------
    pwm: pwm from self.control 
    
    Return:
    -------
    pwm: int, published on '/Command/depth'
    """   
    pwm_min = pwm_neutral - (pwm_max - pwm_neutral)
    if pwm > pwm_max :
        pwm = pwm_max
    if pwm < pwm_min:
        pwm = pwm_min
    return int(pwm)