#include "conv_kernel.hpp" 
#include <cstring>

void Conv2DRef(const float* input,
		const float* kernel,
		float* output,
		const Conv2DDesc& desc){
	for(int oc = 0; oc < desc.out_channels; ++oc){
		for (int oy = 0; oy < desc.out_height; ++oy){
			for( int ox = 0; ox < desc.out_width; ++ox){
				float sum = 0;

				for(int ic = 0; ic < desc.in_channels; ++ic){
					for (int ky = 0; ky < desc.kernel_height; ++ky){
						for (int kx = 0; kx < desc.kernel_width; ++kx){
							int ix = ox * desc.stride_x + kx - desc.padding_x;
							int iy = oy * desc.stride_y + ky - desc.padding_y;
							if (ix >=0 && ix < desc.in_width &&
									iy >=0 && iy < desc.in_height) {
								int input_idx = ic * desc.in_height * desc.in_width + ix;
								int kernel_idx = oc * desc.in_channels * desc.kernel_height * desc.kernel_width +
									ky * desc.kernel_width + kx;
								sum += input[input_idx] * kernel[kernel_idx];
							}
						}
					}
				}
				int out_idx = oc * desc.out_height * desc.out_width + oy * desc.out_width + ox;
				output[out_idx] = sum;
			}
		}
	}
}


void conv_kernel(const float* input,
		const float* kernel,
		float* output,
		const Conv2DDesc& desc)
{
	/* TODO main interface for the conv_kernel
	  should ideally create a structure 
	  for memory formats and stuff
	  think hard. 
	*/
 	// Ref implementation for now 
	// TODO add support for padding and stride logic
	
	Conv2DRef(input,
			kernel,
			output,
			desc);

	
}
