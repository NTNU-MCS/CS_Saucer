function K=thrusterindeadzone(mode,alpha,C)
    % Constraints for Thruster-Thruster interaction. Can be seen in "Initfile"
    C1 = C(1,:);                    % Angle constraints Thruster 1
    C2 = C(2,:);                    % Angle constraints Thruster 2
    C3 = C(3,:);                    % Angle constraints Thruster 3
    
    n_a = mode+1;                   % Columns in Te matrix
    K = ones(1,n_a);                % Resets K For each time iteration
    switch mode
       case 1,
           %Thruster 1&2 on/off
            if abs(alpha(1)) > C1
                K(1) = 0;           %x-component 0
                K(2) = 0;           %y-component 0
            end
        case 2,
           %Thruster 1&2 on/off
            if abs(alpha(1)) > C1
                K(1) = 0;           %x-component 0
                K(2) = 0;           %y-component 0
            end
            % Thruster 3 on/off
            if abs(alpha(2)) < C3(1) || abs(alpha(2)) > C3(2)
                K(3) = 0;
            end
        case 3,
           %Thruster 1 on/off
            if abs(alpha(1)) > C1
                K(1) = 0;           %x-component 0
                K(2) = 0;           %y-component 0
            end
            % Thruster 2 on/off
            if abs(alpha(2)) > C2
                K(3) = 0;
                K(4) = 0;
            end
        case 4,
           %Thruster 1 on/off
            if abs(alpha(1)) > C1
                K(1) = 0;           %x-component 0
                K(2) = 0;           %y-component 0
            end
            % Thruster 2 on/off
            if abs(alpha(2)) > C2
                K(3) = 0;
                K(4) = 0;
            end
            % Thruster 3 on/off
            if abs(alpha(3)) < C3(1) || abs(alpha(3)) > C3(2)
                K(5) = 0;
            end
    end
end