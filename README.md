# Hand-gesture-controled-Arduino-car-using-machine-learning-model

# overview
### In some situations, we only have limited amout of dataset, but we still want to train a very robust machine learning model ourselves. So, it's a very good way to use some pre-trained models created by professionals before. These models have good structures and contain a large amout of pre-trained parameters which can deal with problem that you only have very small dataset. And you can easily load these models from 'Keras'. VGG16 is one of the good examples which has been widely used.

### The basic structure of VGG16
![17](https://user-images.githubusercontent.com/37478093/47568634-3a210680-d964-11e8-8f55-1f5d9526c3ce.png)


### 1. 'taking picture' file is to create your own dataset by taking a lot of pictures in each class

### 2. 'train_own_model_from_vgg16' file is to train your customized model by loading vgg16 from keras and using your own dataset

### 3. 'tkinter with opencv with keras model' file is to create a user interface embeded with hand gesture recognition using the model you trained before.

# Four classes

### stop '0'                                          

![imag11](https://user-images.githubusercontent.com/37478093/47567863-2eccdb80-d962-11e8-82dd-8bdc66b3f24f.jpg)

### run forward '1' 

![imag20](https://user-images.githubusercontent.com/37478093/47567889-4015e800-d962-11e8-816c-9754966c89b3.jpg)

### turn left '2'                             

![imag5](https://user-images.githubusercontent.com/37478093/47567909-499f5000-d962-11e8-8999-0a4d5fe58763.jpg)

### turn right '3'
![imag3](https://user-images.githubusercontent.com/37478093/47567932-54f27b80-d962-11e8-95a9-f9ccc8077d6c.jpg)


# tkinter GUI and test result
![489z9rxq3e raajv f8 i6j](https://user-images.githubusercontent.com/37478093/47569456-3f7f5080-d966-11e8-9511-53db6557e2b8.png)
![135hxg25a 4ta 1o7nx9 mx](https://user-images.githubusercontent.com/37478093/47569466-44440480-d966-11e8-81e4-8ddf8f5d0282.jpg)
![z 6 _ xl 7aoqiq _ o3](https://user-images.githubusercontent.com/37478093/47569474-4908b880-d966-11e8-87e8-e39db099d5a6.png)
![g 1 vo i0rsy1 3jj brit](https://user-images.githubusercontent.com/37478093/47569479-4c9c3f80-d966-11e8-8c25-50be278db2d7.png)


