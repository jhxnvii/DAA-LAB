import os
import zipfile
import cv2

# Path to the zip file containing images
zip_file_path ="C:\Users\KIIT\OneDrive - kiit.ac.in\Desktop\Images"

# Create a directory to store the filtered images
if not os.path.exists("filtered_images"):
    os.makedirs("filtered_images")

# Extract the images
with zipfile.ZipFile(zip_file_path, 'r') as zip_ref:
    zip_ref.extractall("extracted_images")

# List of languages and their respective images
languages = ["Bangla", "English", "Hindi", "Odia"]
image_names = {"Bangla": ["B1", "B2", "B3", "B4"],
               "English": ["E1", "E2", "E3", "E4"],
               "Hindi": ["H1", "H2", "H3", "H4"],
               "Odia": ["O1", "O2", "O3", "O4"]}

# Define two filtering techniques (e.g., Gaussian blur and Median blur)
def apply_filters(image):
    smoothed_image1 = cv2.GaussianBlur(image, (5, 5), 0)
    smoothed_image2 = cv2.medianBlur(image, 5)
    return smoothed_image1, smoothed_image2

# Loop through the folders and process the images
for language in languages:
    for image_name in image_names[language]:
        image_path = os.path.join("extracted_images/Images", language, image_name + ".jpg")
        image = cv2.imread(image_path)

        # Apply filtering techniques
        filtered_image1, filtered_image2 = apply_filters(image)

        # Save the filtered images
        cv2.imwrite(f"filtered_images/{language}_{image_name}_filtered1.jpg", filtered_image1)
        cv2.imwrite(f"filtered_images/{language}_{image_name}_filtered2.jpg", filtered_image2)

# Clean up: remove the extracted images if needed
# You can remove the "extracted_images" folder if you no longer need it

# Optionally, create a zip file with the filtered images
with zipfile.ZipFile("filtered_images.zip", 'w', zipfile.ZIP_DEFLATED) as zipf:
    for language in languages:
        for image_name in image_names[language]:
            for i in range(1, 3):  # Two filtered images for each
                image_path = f"filtered_images/{language}_{image_name}_filtered{i}.jpg"
                zipf.write(image_path, os.path.basename(image_path))
