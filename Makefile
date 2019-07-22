# Makefile for examples

LIBS=-lm -lbcm2835
EX_DIR=Examples/



printgrid: $(EX_DIR)print_grid.cpp 

	$(CXX) -IHeaders/ MLX90641_API.cpp MLX90641_I2C_Driver.cpp $< -o $@  $(LIBS)

bcm2835-1.59.tar.gz:
	wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.59.tar.gz

bcm2835-1.59: bcm2835-1.59.tar.gz
	tar xzvf bcm2835-1.59.tar.gz

bcm2835: bcm2835-1.59
	cd bcm2835-1.59; ./configure; make; sudo make install

