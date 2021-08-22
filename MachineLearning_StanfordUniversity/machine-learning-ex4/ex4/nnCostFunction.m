function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
m = size(X, 1);
X1 = [ones(m, 1) X];
z2= X1 * (Theta1');
a2 = sigmoid(z2);
a2 = [ones(m, 1) a2];

z3=a2 * (Theta2');
a3 = sigmoid(z3);
%extend y
eye_matrix = eye(num_labels);
y_mat = eye_matrix(y,:);

error = - y_mat.*(log(a3)) -(1- y_mat).*log(1-a3);
J=sum(sum(error))/m;

%with regularization
Theta1x=Theta1;
Theta2x=Theta2;
Theta1x(:,1)=0;
Theta2x(:,1)=0;

regu=sum(sum(Theta2x.^2))+sum(sum(Theta1x.^2))
J=J+regu*lambda/(2*m)

% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.

for t = 1:m
    %step one
    a_1= X(t,:);
    a_1 = [1, a_1];
    z_2 = a_1 * (Theta1');
    a_2 = sigmoid(z_2);
    a_2 = [1, a_2];
    z_3=a_2 * (Theta2');
    a_3 = sigmoid(z_3);
    
    %step 2
    y_=y_mat(t,:);
    delta_3 = a_3-y_;
    %step3
    z_2=[0,z_2]
    delta_2 = (delta_3*Theta2).* sigmoidGradient(z_2)
    delta_2 = delta_2(2:end)
    %step4
    Theta1_grad = Theta1_grad + delta_2'*a_1
    Theta2_grad = Theta2_grad + delta_3'*a_2
end
 %step5
    Theta1_grad = Theta1_grad/m
    Theta2_grad = Theta2_grad/m

% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%

   regu1=Theta1x*lambda/m;
   regu2=Theta2x*lambda/m;
   
   Theta1_grad = Theta1_grad+regu1;
   Theta2_grad = Theta2_grad+regu2;

% -------------------------------------------------------------

% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
