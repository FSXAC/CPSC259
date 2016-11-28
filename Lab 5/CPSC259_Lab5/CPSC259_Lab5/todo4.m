% lab 5 todo 4
clear;

% connectivity matrix
% No node contains links to itself
% Node 1 contains links to all of the other nodes
% Node 2 contains links to node 1 and node 4
% Node 3 contains no links
% Node 4 contains links to nodes 1, 2, and 3
% Node 5 contains links to nodes 2 and 4.
connectMat = [0 1 0 1 0;
              1 0 0 1 1;
              1 0 0 1 0;
              1 1 0 0 1;
              1 0 0 0 0];

% divide each value in each column by the sum of each coumn
columnSum = sum(connectMat);
for i = [1:5]
  if columnSum(i) ~= 0
    connectMat([1:end], i) = connectMat([1:end], i) ./ columnSum(i);
  end
end

% get probability matrix S
SMat = connectMat;
SMatSum = sum(SMat);
for i = [1:5]
  if SMatSum(i) == 0
    SMat([1:end], i) = 1/5;
  end
end

% random walk probability factor
