import numpy as np
from math import log10, sqrt
import cv2

def PSNR(original, compressed): #copied from https://www.geeksforgeeks.org/python-peak-signal-to-noise-ratio-psnr/
    mse = np.mean((original - compressed) ** 2) 
    if(mse == 0):  # MSE is zero means no noise is present in the signal . 
                  # Therefore PSNR have no importance. 
        return 100
    max_pixel = 255.0
    psnr = 20 * log10(max_pixel / sqrt(mse)) 
    return psnr 

def Unsharpconvolution(Origin:np.ndarray, Mask:np.ndarray)->np.ndarray:
    f = 3
    Modified = np.pad(Origin,((1,1),(1,1),(0,0)),'constant',constant_values=0)
    #print(Modified.shape)
    NewImage = np.array(Origin)
    for h in range(Origin.shape[0]):
        for w in range(Origin.shape[1]):
            vert_start = h
            vert_end = h + f
            horiz_start = w
            horiz_end = w+f
            slice_of_origin = Modified[vert_start:vert_end,horiz_start:horiz_end,2]
            NewImage[h,w,2] = np.sum(slice_of_origin*Mask)
            NewImage[h,w,1] = Origin[h,w,1]
            NewImage[h,w,0] = Origin[h,w,0]


    return NewImage

def Gaussianconvolution(Origin:np.ndarray, Mask:np.ndarray)->np.ndarray:
    f = Mask.shape[0]
    pad = int((f-1)/2)
    Modified = np.pad(Origin,((pad,pad),(pad,pad),(0,0)),'constant',constant_values=0)
    #print(Modified.shape)
    NewImage = Origin
    for h in range(Origin.shape[0]):
        for w in range(Origin.shape[1]):
            for c in range(Origin.shape[2]):
                vert_start = h
                vert_end = h + f
                horiz_start = w
                horiz_end = w+f
                slice_of_origin = Modified[vert_start:vert_end,horiz_start:horiz_end,c]
                NewImage[h,w,c] = np.sum(slice_of_origin*Mask)

    return NewImage

def EdgeDetectionconvolution(Origin:np.ndarray, Mask:np.ndarray)->np.ndarray:
    f = Mask.shape[0]
    pad = int((f-1)/2)
    Modified = np.pad(Origin,((pad,pad),(pad,pad)),'constant',constant_values=0)
    #print(Modified.shape)
    NewImage = np.array(Origin)
    for h in range(Origin.shape[0]):
        for w in range(Origin.shape[1]):
            vert_start = h
            vert_end = h + f
            horiz_start = w
            horiz_end = w+f
            slice_of_origin = Modified[vert_start:vert_end,horiz_start:horiz_end]
            NewImage[h,w] = np.sum(slice_of_origin*Mask)

    return NewImage
    


def main():
    image = cv2.imread('./shibafify.jpg')

    Gaussian3x3sigma0 = np.zeros((5,5))
    Gaussian3x3sigma0[2,2] = 1
    Gaussian3x3sigma0 = cv2.GaussianBlur(Gaussian3x3sigma0,(3,3),0)[1:4,1:4]
    #print("Gaussian3x3sigma0:\n",Gaussian3x3sigma0)
    edit_image = Gaussianconvolution(image,Gaussian3x3sigma0)
    cv2.imwrite(f"./Gaussian3x3sigma0.png",edit_image)
    print("Gaussian3x3sigma0's PSNR is :",PSNR(image,edit_image),'\n')
        
    Gaussian5x5sigma0 = np.zeros((7,7))
    Gaussian5x5sigma0[3,3] = 1
    Gaussian5x5sigma0 = cv2.GaussianBlur(Gaussian5x5sigma0,(5,5),0)[1:6,1:6]
    #print("Gaussian5x5sigma0:\n",Gaussian5x5sigma0)
    edit_image = Gaussianconvolution(image,Gaussian5x5sigma0)
    cv2.imwrite(f"./Gaussian5x5sigma0.png",edit_image)
    print("Gaussian5x5sigma0's PSNR is :",PSNR(image,edit_image),'\n')

    Gaussian7x7sigma0 = np.zeros((9,9))
    Gaussian7x7sigma0[4,4] = 1
    Gaussian7x7sigma0 = cv2.GaussianBlur(Gaussian7x7sigma0,(7,7),0)[1:8,1:8]
    #print("Gaussian7x7sigma0:\n",Gaussian7x7sigma0)
    edit_image = Gaussianconvolution(image,Gaussian7x7sigma0)
    cv2.imwrite(f"./Gaussian7x7sigma0.png",edit_image)
    print("Gaussian7x7sigma0's PSNR is :",PSNR(image,edit_image),'\n')
    
    Gaussian3x3sigma1 = np.zeros((5,5))
    Gaussian3x3sigma1[2,2] = 1
    Gaussian3x3sigma1 = cv2.GaussianBlur(Gaussian3x3sigma1,(3,3),1)[1:4,1:4]
    #print("Gaussian3x3sigma1:\n",Gaussian3x3sigma1)
    edit_image = Gaussianconvolution(image,Gaussian3x3sigma1)
    cv2.imwrite(f"./Gaussian3x3sigma1.png",edit_image)
    print("Gaussian3x3sigma1's PSNR is :",PSNR(image,edit_image),'\n')

    Gaussian3x3sigma10 = np.zeros((5,5))
    Gaussian3x3sigma10[2,2] = 1
    Gaussian3x3sigma10 = cv2.GaussianBlur(Gaussian3x3sigma10,(3,3),10)[1:4,1:4]
    #print("Gaussian3x3sigma10:\n",Gaussian3x3sigma10)
    edit_image = Gaussianconvolution(image,Gaussian3x3sigma10)
    cv2.imwrite(f"./Gaussian3x3sigma10.png",edit_image)
    print("Gaussian3x3sigma10's PSNR is :",PSNR(image,edit_image),'\n')
    
    Gaussian3x3sigma30 = np.zeros((5,5))
    Gaussian3x3sigma30[2,2] = 1
    Gaussian3x3sigma30 = cv2.GaussianBlur(Gaussian3x3sigma30,(3,3),30)[1:4,1:4]
    #print("Gaussian3x3sigma30:\n",Gaussian3x3sigma30)
    edit_image = Gaussianconvolution(image,Gaussian3x3sigma30)
    cv2.imwrite(f"./Gaussian3x3sigma30.png",edit_image)
    print("Gaussian3x3sigma30's PSNR is :",PSNR(image,edit_image),'\n')
    
    HSVimage = cv2.cvtColor(image,cv2.COLOR_BGR2HSV)
    Unsharp = np.array([[-1,-1,-1],
                        [-1,8,-1],
                        [-1,-1,-1]])
    edit_image = Unsharpconvolution(HSVimage,Unsharp)
    cv2.imwrite(f"./Unsharp.png",cv2.cvtColor(edit_image,cv2.COLOR_HSV2BGR))

    GRAYimage = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
    EdgeDetection = np.array([[1,1,1],
                              [0,0,0],
                              [-1,-1,-1]])
    edit_image = EdgeDetectionconvolution(GRAYimage,EdgeDetection)
    cv2.imwrite(f"./EdgeDetection.png",edit_image)



if __name__ == "__main__":
    main()
