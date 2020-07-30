CSCI 103 Image Filtering Programming Assignment 

Name: Shannon Brownlee

Email Address: sbrownle@usc.edu

Answer the questions posed in the writeup below.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

:discussion with peers, CP on Monday, discussion in class

================================ Questions ==================================

1. 

: The size of the largest padded image you'd need is 266x266 pixels. The upper-
left pixel of the original image would be placed at index [N/2][N/2].
The lower-right pixel of the original image would be placed at index
[SIZE-N/2][SIZE-N/2], with SIZE being the maximum index. 

2. 

: raw - 0.7788, 0.8825, 0.7788

	    0.8825, 1.0000, 0.8825

     	0.7788, 0.8825, 0.7788
normalized - 
        0.1019, 0.1154, 0.1019

	    0.1154, 0.1308, 0.1154

		0.1019, 0.1154, 0.1019

If we used the raw kernel values, the colors would all be brightened since
the sum of the values inside the kernel would be greater than the maximum
for the kernel.

3. 
: Gaussian Blur - If you hold N constant and vary sigma, the values of individual 
    pixels change more. There is a point at which increasing sigma does not perceptibly
    change the blur.
    If you vary N and hold sigma, there is a larger area affected by the blur.
    Higher values of N result in a more blurred output, while lower values on N result
    in a less blurred output. The value of N ultimately has a larger affect on the resulting image.
Sobel - It appears that the Sobel filter detects edges in the image. This effect highlights
    the edges and changes other parts of the image to black.
Gaussian Blur/Unsharp - After blurring an image with the Gaussian Blue and then attempting 
    to undo that with the unsharp-mask filter does not result in the original image. Because
    of the clamping within the blur operator, the values are not completely accurate when the
    unsharp filter is applied to the image, resulting in the unsharpened values being different
    from the original.

4. 

: The number of calculations increases at a rate of N^2 as the size of N increases. Since the
program requires every pixel in the input to be multiplied by each element in the kernel, 
there are more calculations needed when there are more elements in the kernel.
Number of calculations: SIZE^2 * N^2 * 3


================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

:

Do you have any other remarks?

:
