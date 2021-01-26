

#ifndef HAL_MACROS_H_
#define HAL_MACROS_H_

#define set_bit(var,bit_no)  var|=(1<< bit_no)
#define clr_bit(var,bit_no)  var&= ~( 1<< bit_no)
#define toggle_bit(var,bit_no)  var ^= (1<< bit_no)

#define set_nibble_low(var)  var |= (0b00001111)
#define clr_nibble_low(var)  var &= (0b11110000)
#define toggle_nibble_low(var)  var ^= (0b00001111)

#define set_nibble_high(var)  var |= (0b11110000)
#define clr_nibble_high(var)  var &= (0b00001111)
#define toggle_nibble_high(var)  var ^=(0b11110000)

#define assign_bit(var,bit_no,value)  (value==0)? (clr_bit(var,bit_no)) : (set_bit(var,bit_no))

#define get_bit(var,bit_no)  ((var>>bit_no) & 1)

#endif /* HAL_MACROS_H_ */
