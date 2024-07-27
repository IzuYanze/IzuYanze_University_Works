import numpy as np
import gc
import cv2
from tqdm import tqdm
import math
import os
from multiprocessing import Pool

def mandelbrot_set(iteration:int, resolution:tuple, border:tuple)->np.ndarray:
    def build_grid()->np.ndarray:
        xline = np.linspace(border[0],border[1],resolution[0])
        yline = np.linspace(border[2],border[3],resolution[1])
        x,y = np.meshgrid(yline,xline)
        return x+1j*y #j: sqrt(-1) image unit
    
    #print(border)
    c = build_grid()
    #print(c.shape)
    z = (0+0j)*np.ones((resolution[0], resolution[1]))
    background = np.zeros((resolution[0], resolution[1], 3))
    lastmask = np.ones((resolution[0], resolution[1], 3))
    
    color = np.array([255,0,0])  
    
    for i in tqdm(range(iteration)):
            
        mask = (abs(z) <= 2).astype(np.int32)
        # discard escaped value
        z = z*mask 
        mask = np.repeat(mask[:,:,np.newaxis], 3, axis=2)

        # union along all previous iteration by using the concept of bit-wised AND 
        mask = lastmask*mask 
        
        # Only color for the different pos
        # Please make color smoothly change along with each iteration 
        # Your code for changing color:
        
        color = np.array([192 + 32* math.sin(i/10),128,192 + 32* math.cos(i/10)])
        
        #  
        framei=(lastmask - mask)*color
        
        
        background += framei
        lastmask = mask
        # update z : you need to implement this. You can go to check the formula for mandelbrot set
        # Your code:
        
        z = z*z + c

        # free mem
        del mask, framei
        gc.collect()

    return background.astype(np.uint8)

def f(i):
    itera_frame = mandelbrot_set(iteration=i, resolution=(2000,2500),border=((-1.5-0.5*math.pow(0.99,i-19)),(-1.5+3.5*math.pow(0.99,i-19)),2*-math.pow(0.99,i-19),2*math.pow(0.99,i-19)))
    cv2.imwrite(f"./m{i+1:03}.png", itera_frame)

def main():
    """
    The sample code for generating a frame.
    
    Can use ```opencv-python``` package cv2
    (https://pypi.org/project/opencv-python/)
    
    The order of the channel for color image when using cv2 is BGR:
    - img[...,0]: Blue channel
    - img[...,1]: Green channel
    - img[...,2]: Red channel 

    for image and video I/O
    - write a video: 
        videowriter = cv2.VideoWriter(vidoe_name, cv2.VideoWriter_fourcc('m','p','4','v'), 10.0, (resolutionY, resolutionX))  
    
    when writing a frame, just use:
        videowriter.write(a_frame_image)

    >>> a 3*4 gray image:
    >>> [
    >>>    [255, 234, 0, 3],
    >>>    [100, 0, 255, 36],
    >>>    [30, 125, 77, 150]
    >>> ]
        
    Please note that :
    
    - The dtype for image to write must be 8 bit unsigned int  (np.uint8).

    - The shape when writing a frame into a cv2.VideoWriter.
    If resolution of your videowriter is (a, b), 
    each frame you give must be (b, a ,3(BGR)).
    If the shape of some frames are not right for the videowriter, the .mp4 video
    you write using that videowriter will not be able to play.
    """ 
    """
    DistanceLeft = 0.5
    DistanceRight = 3.5
    DistanceUp = 2
    DistanceDown = 2
    for i in range(20,22):
        itera_frame = mandelbrot_set(iteration=i, resolution=(2000,2500),border=((-1.5-DistanceLeft),(-1.5+DistanceRight),-DistanceDown,DistanceUp))
        cv2.imwrite(f"./m{i+1:03}.png", itera_frame)
        DistanceLeft *= 0.9
        DistanceRight *= 0.9
        DistanceUp *= 0.9
        DistanceDown *= 0.9
    """
    with Pool(4) as pool:
        pool.map(f,range(20,169))
    videowriter = cv2.VideoWriter("./Mandelbrot.mp4", cv2.VideoWriter_fourcc('m','p','4','v'), 5.0, (2500, 2000))  

    for photo in sorted(os.listdir("./")):
        if photo.startswith("m"):
            if photo.endswith('.png'):
                videowriter.write(cv2.imread(photo))



if __name__ == "__main__":
    """
    This code is just an example for generating 1 frame.

    Please generate many frames along with zoom in to make a video
    for observing the detail for one point (cx, cy).  
    """
    main()