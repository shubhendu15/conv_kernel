#ifndef CONV_KERNEL_H
#define CONV_KERNEL_H
struct Conv2DDesc {
	int in_width;
	int in_height;
	int out_width;
	int out_height;
	int kernel_width;
	int kernel_height;
	int stride_x;
	int stride_y;
	int padding_x;
	int padding_y;
	int in_channels;
	int out_channels;
};

void conv_kernel( const float* input,
		 const float* kernel,
		 float* output,
		 const Conv2DDesc& desc);


#endif // CONV_KERNEL_H
