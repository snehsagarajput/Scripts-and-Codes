#!pip install tensorflow==2.3.0

##########################################################################
#                                                                        #
#                                                                        #
#                                                                        #
#  https://github.com/opencv/opencv/issues/16582#issuecomment-586592023  #
#                    As mentioned in above issue                         #
#                                                                        #
#                                                                        #
##########################################################################

import tensorflow as tf
from tensorflow.python.framework.convert_to_constants import convert_variables_to_constants_v2
import os 

def convert(model, log_dir = os.getcwd(), DEBUG_LOGS=False):
    '''model   : tf-keras model'''
    '''log_dir : directory for logs and saving model
                 default to current working directory'''

    try:
        # Convert Keras model to ConcreteFunction
        full_model = tf.function(lambda x: model(x))
        full_model = full_model.get_concrete_function(
            tf.TensorSpec(model.inputs[0].shape, model.inputs[0].dtype))

        # Get frozen ConcreteFunction
        frozen_func = convert_variables_to_constants_v2(full_model)
        frozen_func.graph.as_graph_def()

        layers = [op.name for op in frozen_func.graph.get_operations()]
        if DEBUG_LOGS:
            print("-" * 50)
            print("Frozen model layers: ")
            for layer in layers:
                print(layer)

            print("-" * 50)
            print("Frozen model inputs: ")
            print(frozen_func.inputs)
            print("Frozen model outputs: ")
            print(frozen_func.outputs)

        tf.io.write_graph(graph_or_graph_def=frozen_func.graph,
                    logdir=log_dir,
                    name="frozen_graph.pb",
                    as_text=False)
        print("Success\nCheck ",log_dir," for output file.")
    
    except:
        print("Failed.")
    



