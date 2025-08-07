#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <webots/keyboard.h>
#include <webots/motor.h>
#include <webots/robot.h>
#include <time.h> 
#include <stdio.h> 
#define N_PARTS 45

static WbDeviceTag robot_parts[N_PARTS];
static void check_keyboard() {
 

  int key = wb_keyboard_get_key();
  if (key >= 0) {
    switch (key) {
      case WB_KEYBOARD_UP: 
      wb_motor_set_position(robot_parts[10],1.57); 
      wb_motor_set_position(robot_parts[15],0.40);
      wb_motor_set_position(robot_parts[19],0.70);
      wb_motor_set_position(robot_parts[26],0.70);
      wb_motor_set_position(robot_parts[29],-0.30);
      wb_motor_set_position(robot_parts[33],0.70);
      wb_motor_set_position(robot_parts[36],-0.40);
      wb_motor_set_position(robot_parts[40],0.70);
     // wb_motor_set_position(robot_parts[19],0.60);
     // wb_motor_set_position(robot_parts[21],0.79);
     // wb_motor_set_position(robot_parts[16],0.60);
        break;
      case WB_KEYBOARD_DOWN:
        wb_motor_set_position(robot_parts[6],1.65);
        break;
     case WB_KEYBOARD_RIGHT: 
      wb_motor_set_position(robot_parts[11],0.79); 
      wb_motor_set_position(robot_parts[19],0.79);
       wb_motor_set_position(robot_parts[21],0.79);
      wb_motor_set_position(robot_parts[26],0.79);
       wb_motor_set_position(robot_parts[28],0.79);
      wb_motor_set_position(robot_parts[33],0.79);
    //  wb_motor_set_position(robot_parts[42],0.79);
        break;
      case WB_KEYBOARD_LEFT:
      wb_motor_set_position(robot_parts[5],-2.00);
        break;
      
    }
    
  } 

}

int main(int argc, char **argv) {
  // init webots stuff
  wb_robot_init();

  const int time_step = wb_robot_get_basic_time_step();

  // initialize the robot's information
  const char *names[N_PARTS] = {"head_2_joint",
                                "head_1_joint",
                                "torso_lift_joint",
                                "arm_1_joint",
                                "arm_2_joint",
                                "arm_3_joint",
                                "arm_4_joint",
                                "arm_5_joint",
                                "arm_6_joint",
                                "arm_7_joint",
                                "hand_right_thumb_abd_joint",
                                "hand_right_thumb_virtual_1_joint",
                                "hand_right_thumb_flex_1_joint",
                                "hand_right_thumb_virtual_2_joint",
                                "hand_right_thumb_flex_2_joint",
                                "hand_right_index_abd_joint",
                                "hand_right_index_virtual_1_joint",
                                "hand_right_index_flex_1_joint",
                                "hand_right_index_virtual_2_joint",
                                "hand_right_index_flex_2_joint",
                                "hand_right_index_virtual_3_joint",
                                "hand_right_index_flex_3_joint",
                                "hand_right_middle_abd_joint",
                                "hand_right_middle_virtual_1_joint",
                                "hand_right_middle_flex_1_joint",
                                "hand_right_middle_virtual_2_joint",
                                "hand_right_middle_flex_2_joint",
                                "hand_right_middle_virtual_3_joint",
                                "hand_right_middle_flex_3_joint",
                                "hand_right_ring_abd_joint",
                                "hand_right_ring_virtual_1_joint",
                                "hand_right_ring_flex_1_joint",
                                "hand_right_ring_virtual_2_joint",
                                "hand_right_ring_flex_2_joint",
                                "hand_right_ring_virtual_3_joint",
                                "hand_right_ring_flex_3_joint",
                                "hand_right_little_abd_joint",
                                "hand_right_little_virtual_1_joint",
                                "hand_right_little_flex_1_joint",
                                "hand_right_little_virtual_2_joint",
                                "hand_right_little_flex_2_joint",
                                "hand_right_little_virtual_3_joint",
                                "hand_right_little_flex_3_joint",
                                "wheel_left_joint",
                                "wheel_right_joint"};

  double target_pos[N_PARTS] = {0.24,  -0.67, 0.20, 0.20, 0.00 , -1.50, 1.52, -2.07,    0.00,   0.40, 0.00,  0.00,
                                0.00,  0.00,  0.00, -0.00, 0.00, 0.00,  0.00, 0.00,     0.00,    0.00 , -0.00, 0.00,
                                0.00,  0.00,  0.00, 0.00, 0.00, -0.00, 0.00, 0.00,     0.00,    0.00, 0.00,  0.00,
                                0.00, 0.00,  0.00, 0.00, 0.00, 0.00, 0.00 , 0.00, 0.00};
 
  // configures and achieves the robot's position desired
  for (int i = 0; i < N_PARTS; i++) {
    robot_parts[i] = wb_robot_get_device(names[i]);
    wb_motor_set_velocity(robot_parts[i], wb_motor_get_max_velocity(robot_parts[i]) / 2.0);
    wb_motor_set_position(robot_parts[i], target_pos[i]);
  }
   
 
  // enable keyboard
  wb_keyboard_enable(time_step);
  while (wb_robot_step(time_step) != -1) {
    check_keyboard();

 };

  wb_robot_cleanup();
  return 0;
}