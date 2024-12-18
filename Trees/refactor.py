import os
import shutil

# Current directory
current_dir = r"D:\Learning\DSA\Trees"

# Map of concepts to files
concept_map = {
    "AVL": ["AVL.py", "AVL_ADT_2.c", "AVL_ADT_2.exe"],
    "BST": ["BST.c", "BST.exe", "BST-ADT.c", "BST-ADT.exe"],
    "BT": ["BT-ADT.c", "BT-ADT.exe"],
    "DFS": ["DFS.c", "DFS.exe"],
    "Heap": ["heap-ADT.c", "heap-ADT.exe", "heap.py"],
    "PCA": ["pca.py"],
    "ADT": ["ADT.c", "ADT.exe"],
}

# Create directories and move files
for concept, files in concept_map.items():
    # Create a folder for the concept
    concept_folder = os.path.join(current_dir, concept)
    os.makedirs(concept_folder, exist_ok=True)
    
    for file in files:
        file_path = os.path.join(current_dir, file)
        if os.path.exists(file_path):
            # Move file to the concept folder
            shutil.move(file_path, os.path.join(concept_folder, file))
            print(f"Moved {file} to {concept_folder}")

# Print final structure
print("File restructuring complete.")
