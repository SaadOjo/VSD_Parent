J_rwy = 0.74;
J_fwy = 0.48;
J_s = 0.41;
r = 0.278;
rt_fw = 0.0388;
k_mzfc = 0.0247;
k_mzfa = 0.2565;
m_m = 274.8;
g = 9.81;

epsilon = 27.72 * (pi/180);

torque_f = 1;
torque_r = 1;
torque_s = 1;

x_dot = 1;
phi = 1;


c_steer = 0;

lambda_f = abs((x_dot - theta_f_dot)/x_dot);
lambda_r = abs((x_dot - theta_r_dot)/x_dot);

F_xf = F_zf*k_lambda_f*lambda_f;
F_xr = F_zr*k_lambda_r*lambda_r;

% Tyre dynamic equations
theta_f_dot_dot = (r*F_xf + torque_f)/J_fwy;
theta_r_dot_dot = (r*F_xr + torque_r)/J_rwy;

% Steering Dynamic Equation
s_epsilon = sin(epsilon);
c_epsilon = cos(epsilon);
c_phi = cos(phi);
s_phi = sin(phi);

M_xf = F_zf*rt_fw*tan(phi + s_epsilon*delta); 

 
delta_dot_dot = (s_epsilon*M_xf - ...
                 J_fwy*theta_f_dot*(c_epsilon*phi_dot + s_epsilon*c_phi*psi_dot) + ...
                 c_epsilon*c_phi*M_zf - ...
                 (r*s_epsilon - d)*c_phi*F_yr - ...
                 (r*s_epsilon - d)*s_phi*F_zf - ...
                 c_steer*delta_dot + ...
                 torque_s)/J_s;
                                
 M_zf = F_zf*(k_mzfc*(phi + s_epsilon*delta) + k_mzfa*alpha_f) - ...
              F_xf*rt_fw*tan(phi + s_epsilon*delta);

F_yf = F_zf*(k_af*alpha_f + k_cf*(phi + s_epsilon*delta));

eight = (F_xf + F_xr + F_drag)/m_m;

%c_phi_phi = cos(phi_phi)
%x_dot_dot - (beta*x_dot - h_m*phi_phi_dot*c_phi_phi)*psi_dot

F_drag = -0.5*rho*C_d*A_aero*(x_dot^2);
F_lift = -0.5*rho*C_l*A_aero*(x_dot^2);

%m_m*(beta*x_dot_dot + beta_dot*x_dot) + m_m*(h_m*c_phi*phi_dot_dot - h_m*s_phi*(phi_dot)^2)
%=
%-m_m*x_dot*psi_dot + F_yr + F_yf - s_phi*F_lift;


F_yr = F_zr*(k_ar*alpha_r + k_cr*phi);

phi_dot_dot = (M_xr + M_xf + J_rwy*c_phi*psi_dot*theta_r_dot + ...
               J_fwy*(c_phi*psi_dot + c_epsilon*delta_dot)*theta_f_dot - ...
               h_m*c_phi*(F_yr + F_yf) - ...
               h_m*s_phi*(F_zr + F_zf))/J_mx;


M_zr = F_zr*(k_mzrc*phi + k_mzra*alpha_r) - F_xr*rt_rw*tan(phi);

M_pitch = 0.5*rho*C_p*A_aero*L_w*b*(x_dot^2);

psi_dot_dot = (M_zr + M_zf - J_fwy*phi_dot*theta_f_dot - J_rwy*c_phi*phi_dot*theta_r_dot - ...
               a_m*F_yr + h_m*s_phi*F_xr + b_m*F_yf + h_m * s_phi * F_xf + s_phi*M_pitch)/(J_my*(s_phi^2) + J_mz*(c_phi^2));
           
           
a_f_dot =  (x_dot*(a_f - a_f0))/L_yf;

a_r_dot =  (x_dot*(a_r - a_r0))/L_yr;

%F_z + F_r = fifteen

fifteen = m_m*(h_m*s_phi*phi_dot_dot + h_m*c_phi*(phi_dot^2) - m_m*g - c_phi*F_lift);

F_zr = -(h_m*c_phi*F_xr - b_m*F_zf + h_m*c_phi*F_xf + ...
         c_phi*M_aero + J_fwy*s_phi*phi_dot * theta_f_dot + ...
         J_rwy*s_phi*phi_dot*theta_r_dot)/a_m;

           




