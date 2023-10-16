# Define the file path
file_path = '/home/MAPS/spam.txt  # Replace with the actual path to your file

# Initialize a counter for the word "spam"
spam_count = 0

# Open the file in read mode
try:
    with open(file_path, 'r') as file:
        for line in file:
            # Split the line into words using space as the delimiter
            words = line.split()
            for word in words:
                if word == "spam":
                    spam_count += 1
                else:
                    # If a word other than "spam" is encountered, stop and return the count
                    print(f"Encountered a word other than 'spam'. Stopping...")
                    break
except FileNotFoundError:
    print(f"File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {str(e)}")

# Print the count of the word "spam"
print(f"Count of 'spam': {spam_count}")
