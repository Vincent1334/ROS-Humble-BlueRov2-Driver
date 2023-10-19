# Tritech Micron configuration parameters.

# Header message.
std_msgs/Header header

# Whether the sonar head is facing upwards.
bool inverted

# Whether the scan is continuous or in sector scan mode.
bool continuous

# Whether the scan is clockwise.
bool scanright

# Whether the scan intensity is an 8-bit or 4-bit number.
bool adc8on

# Initial gain of the sonar pulse. Ranges between 0 and 1.
float64 gain

# Mapping of intensity to dB. Ranges from 0 to 80 dB.
float64 ad_low
float64 ad_high

# Right and left limit of scan if in sector scan mode. Values are in radians
# and range from 0 to 2 pi.
float64 left_limit
float64 right_limit

# Range of scan in meters.
float64 range

# Number of bins per scan slice.
int16 nbins

# Motor step size in radians.
float64 step