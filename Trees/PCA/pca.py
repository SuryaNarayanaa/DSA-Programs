import numpy as np
from sklearn.decomposition import PCA

# Step 1: Example Matrix
X = np.array([
   [2,4],[3,6],[4,8],[5,10]
])

# Step 2: Standardize the Data
mean = np.mean(X, axis=0)
X_centered = X - mean

# Step 3: Compute the Covariance Matrix (manual computation)
cov_matrix = np.cov(X_centered.T)

# Step 4: Compute Eigenvalues and Eigenvectors (manual computation)
eigenvalues, eigenvectors = np.linalg.eig(cov_matrix)

# Sort eigenvalues and eigenvectors in descending order
sorted_indices = np.argsort(eigenvalues)[::-1]
eigenvalues = eigenvalues[sorted_indices]
eigenvectors = eigenvectors[:, sorted_indices]

# Step 5: Transform the Data (manual projection)
Z_manual = np.dot(X_centered, eigenvectors)  # Project onto the principal components

# Cross-verify with PCA using sklearn
pca = PCA(n_components=2)
Z_sklearn = pca.fit_transform(X)

# Outputs
print("Original Data Matrix (X):\n", X)
print("Mean of Each Feature:\n", mean)
print("Centered Data Matrix (X_centered):\n", X_centered)
print("Covariance Matrix:\n", cov_matrix)
print("Eigenvalues:\n", eigenvalues)
print("Eigenvectors:\n", eigenvectors)
print("Transformed Data (Manual Calculation, Z_manual):\n", Z_manual)
print("Transformed Data (Sklearn, Z_sklearn):\n", Z_sklearn)
