import pandas as pd
import matplotlib.pyplot as plt

# Load the dataset (Update the file path accordingly)
df = pd.read_csv(r"C:\Users\msi\Downloads\MachineLearningCSV\MachineLearningCVE\Wednesday-workingHours.pcap_ISCX.csv")

# Display first few rows to verify the correct column name
print(df.head())

# Check if 'Label' column exists
if ' Label' in df.columns:
    label_col = ' Label'  # Column has a space at the beginning
elif 'Label' in df.columns:
    label_col = 'Label'
else:
    raise ValueError("Column 'Label' not found in dataset. Check column names.")

# Count occurrences of each attack category
attack_counts = df[label_col].value_counts()

# Define colors for different categories
colors = ['lightblue', 'blue', 'lightgreen', 'green', 'red', 'brown', 'orange', 'yellow', 'blue', 'pink']

# Plot the pie chart
plt.figure(figsize=(10, 6))
attack_counts.plot(kind='pie', autopct='%1.1f%%', colors=colors, startangle=140)

# Add title and legend
plt.title("Distribution of Attack Categories", fontsize=14)
plt.ylabel('')  # Hide the default y-axis label
plt.legend(title="Attack Categories", loc="best")

# Show the pie chart
plt.show()
