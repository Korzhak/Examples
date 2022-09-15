import configparser

config = configparser.ConfigParser()
config.read('config_1.ini')

# showing all sections
for section in config:
    print(section)

# Get section or parameter
example_section = config['EXAMPLE_SECTION']
ip_address = example_section['IP_ADDRESS_VALUE']

# Getting int value
int_value = example_section.getint('INT_VALUE')
print(int_value, type(int_value))

# Getting float value
float_value = example_section.getfloat('FLOAT_VALUE')
print(float_value, type(float_value))

# Getting bool value
bool_value = example_section.getboolean('BOOL_VALUE')
print(bool_value, type(bool_value))

# Getting str value
str_value = example_section.get('STR_VALUE')
print(str_value, type(str_value))
