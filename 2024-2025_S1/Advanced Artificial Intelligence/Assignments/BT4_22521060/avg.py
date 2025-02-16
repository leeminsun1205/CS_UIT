import matplotlib.pyplot as plt
from tensorboard.backend.event_processing.event_accumulator import EventAccumulator
import numpy as np
from torch.utils.tensorboard import SummaryWriter
import os

# Specify the directories containing your TensorBoard logs for 5 runs
logdirs = [
    "D:/2024-2025 S1/Advanced Artificial Intelligence/Assignments/BT4_22521060/runs/ant/22521060/Ant-v4__td3_continuous_action__22521060__1736218453",
    "D:/2024-2025 S1/Advanced Artificial Intelligence/Assignments/BT4_22521060/runs/ant/22521061/Ant-v4__td3_continuous_action__22521061__1736209701",
    "D:/2024-2025 S1/Advanced Artificial Intelligence/Assignments/BT4_22521060/runs/ant/22521062/Ant-v4__td3_continuous_action__22521062__1736221233",
    "D:/2024-2025 S1/Advanced Artificial Intelligence/Assignments/BT4_22521060/runs/ant/22521063/Ant-v4__td3_continuous_action__22521063__1736209804",
    "D:/2024-2025 S1/Advanced Artificial Intelligence/Assignments/BT4_22521060/runs/ant/22521064/Ant-v4__td3_continuous_action__22521064__1736221582",
]

# Specify the directory to save the averaged TensorBoard logs
averaged_logdir = "averaged_runs_single_file/ant_td3"
os.makedirs(averaged_logdir, exist_ok=True)

# Initialize SummaryWriter outside the loop
writer = SummaryWriter(log_dir=averaged_logdir)

# Get all unique scalar keys across all runs
all_scalar_keys = set()
for logdir in logdirs:
    event_acc = EventAccumulator(logdir)
    event_acc.Reload()
    all_scalar_keys.update(event_acc.scalars.Keys())

for scalar_tag in sorted(list(all_scalar_keys)):
    all_runs_data = []
    min_step = float('inf')
    max_step = float('-inf')

    for logdir in logdirs:
        event_acc = EventAccumulator(logdir)
        event_acc.Reload()

        if scalar_tag in event_acc.scalars.Keys():
            scalar_events = event_acc.scalars.Items(scalar_tag)
            steps = [event.step for event in scalar_events]
            values = [event.value for event in scalar_events]
            all_runs_data.append((np.array(steps), np.array(values)))
            min_step = min(min_step, min(steps) if steps else float('inf'))
            max_step = max(max_step, max(steps) if steps else float('-inf'))
        else:
            print(f"Warning: Scalar tag '{scalar_tag}' not found in logdir: {logdir}")

    if not all_runs_data:
        print(f"Warning: Scalar tag '{scalar_tag}' not found in any of the provided log directories.")
        continue

    if min_step == float('inf') or max_step == float('-inf'):
        print(f"Warning: No data found for scalar tag '{scalar_tag}'.")
        continue

    common_steps = np.linspace(min_step, max_step, 1000)

    interpolated_values = []
    for steps, values in all_runs_data:
        if steps.size > 0:
            interp_vals = np.interp(common_steps, steps, values)
            interpolated_values.append(interp_vals)

    if interpolated_values:
        averaged_values = np.mean(interpolated_values, axis=0)

        for step, avg_value in zip(common_steps, averaged_values):
            writer.add_scalar(scalar_tag, avg_value, int(step)) 
        print(f"Averaged data for '{scalar_tag}' written to TensorBoard in '{averaged_logdir}'")
    else:
        print(f"Warning: Could not interpolate data for scalar tag '{scalar_tag}'.")

writer.close()
print(f"All averaged TensorBoard data written to '{averaged_logdir}'")