import math


def get_angle_two_legs(x, y):
    """
    Function for calc angle when you know two legs of a right triangle
    :param x: opposite leg (протилежний катет)
    :param y: adjacent leg (прилеглий катет)
    :return: angle in degrees
    """
    return math.degrees(math.atan2(x, y))


def filter_arctg(preview_x: float, preview_y: float, current_x: float, current_y: float, allowable_angle: float) -> float:
    """
    Function detects angle of inclination of the graphic.
    If the angle of inclination is greater than the permissible one,
    the function returns the previous value of the data
    :param preview_x: preview value on X axis
    :param preview_y: preview value on Y axis
    :param current_x: current value on X axis
    :param current_y: current value on Y axis
    :param allowable_angle: the permissible value of the slope of the graph
    :return: current_y or preview_y
    """
    leg_x = current_x - preview_x
    leg_y = current_y - preview_y
    angle = get_angle_two_legs(leg_x, leg_y)
    return current_y if angle >= allowable_angle else preview_y
