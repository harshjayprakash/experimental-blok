# Provides a list of switches for turning features on and off.
# Please do not touch the if statements in this file. These checks ensure that the
# features for basic functionality are still available.

# Feature: Single Instance
# - Uses a Mutex object to determine if another instance of the application is running.
# - @see CreateMutexW
option(__ST_FEATURE_SINGLE_INSTANCE OFF)