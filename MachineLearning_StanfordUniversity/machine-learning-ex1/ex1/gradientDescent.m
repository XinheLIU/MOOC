function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

dst=X'*(X*theta-y);  %the descent 
theta = theta-alpha*dst/m;
J_history(1) = computeCost(X, y, theta);

for iter = 2:num_iters
    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    % theta. 
    if J_history(iter)<=J_history(iter-1)
        dst=X'*(X*theta-y);  %the descent 
        theta=theta-alpha*dst/m;
    end
    J_history(iter) = computeCost(X, y, theta);
end

end
